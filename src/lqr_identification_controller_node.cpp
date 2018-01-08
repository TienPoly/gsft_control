#include <ros/ros.h>

#include <mav_msgs/default_topics.h>
#include <nav_msgs/Odometry.h>
#include <mav_msgs/eigen_mav_msgs.h>
#include <mav_msgs/conversions.h>

#include <tf/tf.h>
#include <tf_conversions/tf_eigen.h>
#include <trajectory_msgs/MultiDOFJointTrajectory.h>

#include "parameters.h"
#include "parameters_ros.h"
#include "common.h"

#include <gsft_control/LOE.h>
#include <gsft_control/UAVState.h>
#include <lqr_identification.h>

#include <dynamic_reconfigure/server.h>
#include <gsft_control/controllerDynConfig.h>

lqr_identificationModelClass gController;

bool gCommand_active;
bool gLOE_active;
Eigen::VectorXd gLOE(6);

void OdometryCallback(const nav_msgs::Odometry::ConstPtr &odom) {
  mav_msgs::EigenOdometry odometry;
  mav_msgs::eigenOdometryFromMsg(*odom, &odometry);

  gController.lqr_identification_U.X[0 ]  = odometry.position_W.x();
  gController.lqr_identification_U.X[1 ]  = odometry.position_W.y();
  gController.lqr_identification_U.X[2 ]  = odometry.position_W.z();

  Eigen::Matrix3d R_W_B = odometry.orientation_W_B.toRotationMatrix();
  Eigen::Vector3d velocity_W =  R_W_B * odometry.velocity_B;

  gController.lqr_identification_U.X[3 ]  = velocity_W.x();
  gController.lqr_identification_U.X[4 ]  = velocity_W.y();
  gController.lqr_identification_U.X[5 ]  = velocity_W.z();

  double psi, phi, teta;
  psi = atan2(R_W_B(1,0),R_W_B(0,0));
  phi = atan2(R_W_B(2,1),R_W_B(2,2));
  teta = asin(-R_W_B(2,0));

  gController.lqr_identification_U.X[6 ]  = phi;
  gController.lqr_identification_U.X[7 ]  = teta;
  gController.lqr_identification_U.X[8 ]  = psi;

  Eigen::Matrix3d H;
  H << 1.0, sin(phi)*tan(teta), cos(phi)*tan(teta),
       0.0, cos(phi),           -sin(phi),
       0.0, sin(phi)/cos(teta), cos(phi)/cos(teta);
  Eigen::Vector3d euler_rate = H*odometry.angular_velocity_B;

  gController.lqr_identification_U.X[9 ]  = euler_rate.x();
  gController.lqr_identification_U.X[10]  = euler_rate.y();
  gController.lqr_identification_U.X[11]  = euler_rate.z();
}

/*void MultiDofJointTrajectoryCallback(
    const trajectory_msgs::MultiDOFJointTrajectoryConstPtr& msg) {
    mav_msgs::EigenTrajectoryPoint eigen_reference;
    mav_msgs::eigenTrajectoryPointFromMsg(msg->points.front(), &eigen_reference);

    gController.lqr_identification_U.z_ref    = eigen_reference.position_W.z();

    if (!gCommand_active){
      gCommand_active      = true;
      // gCommand_time        = ros::Time::now();
    }
}*/

/*void CommandPoseCallback(const geometry_msgs::PoseStampedConstPtr& pose_msg) {
  mav_msgs::EigenTrajectoryPoint eigen_reference;
  mav_msgs::eigenTrajectoryPointFromPoseMsg(*pose_msg, &eigen_reference);
  gController.lqr_identification_U.x_ref    = eigen_reference.position_W.x();
  gController.lqr_identification_U.y_ref    = eigen_reference.position_W.y();
  gController.lqr_identification_U.z_ref    = eigen_reference.position_W.z();
  gController.lqr_identification_U.psi_ref  = 0.0;
  if (!gCommand_active){
    gCommand_active      = true;
  }
}
*/

void controller_dyn_callback(gsft_control::controllerDynConfig &config, uint32_t level) {
  ROS_INFO("Controller Active Request: %s",config.active_controller?"True":"False");
  if (config.active_controller == true){
      if (!gCommand_active){
        gCommand_active      = true;
        // gCommand_time        = ros::Time::now();
      }
      config.active_controller = false;
  }
}

void LostControlCallback(const gsft_control::LOEConstPtr& loe_msg) {
 for (int i = 0; i < 6; i++) {
    gLOE[i] = loe_msg->LOE[i];
  }
  std::cout << "[ INFO] [" << ros::Time::now() <<
    "]: ---------- TND LOE0 = " << gLOE[0] << std::endl;
}


int main(int argc, char** argv) {
  ros::init(argc, argv, "lqr_identification_controller_node");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");
  ROS_INFO("lqr_identification_controller_node main started");

  ros::Subscriber odometry_sub_;
  odometry_sub_ = nh.subscribe(mav_msgs::default_topics::ODOMETRY, 1, OdometryCallback);

/*  ros::Subscriber cmd_pose_sub_;                    // references (position and yaw)
  cmd_pose_sub_ = nh.subscribe(mav_msgs::default_topics::COMMAND_POSE, 1, CommandPoseCallback); */

  /*ros::Subscriber cmd_multi_dof_joint_trajectory_sub;
  cmd_multi_dof_joint_trajectory_sub = nh.subscribe(mav_msgs::default_topics::COMMAND_TRAJECTORY, 1, MultiDofJointTrajectoryCallback);*/

  ros::Subscriber lost_control_sub_;
  lost_control_sub_ = nh.subscribe(gsft_control::default_topics::LOE, 1, LostControlCallback);

  ros::Publisher motor_RPM_reference_pub_;          // motor speed RPM   => Asctec Firefly test
  motor_RPM_reference_pub_ = nh.advertise<mav_msgs::Actuators>(
        gsft_control::default_topics::COMMAND_RPM, 1);

  ros::Publisher motor_velocity_reference_pub_;     // motor speed rad/s => Gazebo test
  motor_velocity_reference_pub_ = nh.advertise<mav_msgs::Actuators>(
        mav_msgs::default_topics::COMMAND_ACTUATORS, 1);

  ros::Publisher uav_state_pub_;
  uav_state_pub_ = nh.advertise<gsft_control::UAVState>(gsft_control::default_topics::UAV_STATE, 1);

  ros::Rate r(60);

  gCommand_active = false;
  for (unsigned int i=0; i< 6; i++) {
    gLOE[i] = 0.0;
  }
  gController.initialize();

  dynamic_reconfigure::Server<gsft_control::controllerDynConfig> server;
  dynamic_reconfigure::Server<gsft_control::controllerDynConfig>::CallbackType f;
  f = boost::bind(&controller_dyn_callback, _1, _2);
  server.setCallback(f);

  while(ros::ok()) {
    if (gCommand_active) {
        gController.step();
        Eigen::VectorXd motor_RPM(6);           // range 0 .. 10000 RPM
        Eigen::VectorXd motor_command(6);       // range 0 .. 200
        Eigen::VectorXd motor_speed(6);         // range 0 .. 1047 rad/s

        for(unsigned int i=0; i< 6; i++) {
            motor_RPM[i]     = gController.lqr_identification_Y.motor_RPM[i]*(1.0 - gLOE[i]);
            motor_command[i] = gController.lqr_identification_Y.motor_command[i]*(1.0 - gLOE[i]);
            motor_speed[i]   = gController.lqr_identification_Y.motor_speed[i]*(1.0 - gLOE[i]);
        }

        // Publish: RPM and normalized command in 0 .. 200 (Asctec Firefly test)
        mav_msgs::ActuatorsPtr motorRPM_msg(new mav_msgs::Actuators);
        motorRPM_msg->angular_velocities.clear();
        motorRPM_msg->normalized.clear();
        for (int i = 0; i < 6; i++) {
          motorRPM_msg->angular_velocities.push_back(motor_RPM[i]);
          motorRPM_msg->normalized.push_back(motor_command[i]);
        }
        motorRPM_msg->header.stamp =  ros::Time::now();
        motor_RPM_reference_pub_.publish(motorRPM_msg);

        // Publish: Rotor speed rad/s (Gazebo test)
        mav_msgs::ActuatorsPtr actuator_msg(new mav_msgs::Actuators);
        actuator_msg->angular_velocities.clear();
        actuator_msg->normalized.clear();
        for (int i = 0; i < 6; i++) {
          actuator_msg->angular_velocities.push_back(motor_speed[i]);
        }
        actuator_msg->header.stamp =  ros::Time::now();
        motor_velocity_reference_pub_.publish(actuator_msg);
    } else {
      // Controller inactive
      mav_msgs::ActuatorsPtr actuator_msg(new mav_msgs::Actuators);
      actuator_msg->angular_velocities.clear();

      for (int i = 0; i < 6; i++) {
        actuator_msg->angular_velocities.push_back(0.0);
        actuator_msg->normalized.push_back(0.0);
      }
      actuator_msg->header.stamp =  ros::Time::now();
      motor_RPM_reference_pub_.publish(actuator_msg);
      motor_velocity_reference_pub_.publish(actuator_msg);
    }

    // Publish: UAV state in World frame
    gsft_control::UAVStatePtr uav_state_msg(new gsft_control::UAVState);
    uav_state_msg->position_W.x  = gController.lqr_identification_U.X[0];
    uav_state_msg->position_W.y  = gController.lqr_identification_U.X[1];
    uav_state_msg->position_W.z  = gController.lqr_identification_U.X[2];
    uav_state_msg->velocity_W.x  = gController.lqr_identification_U.X[3];
    uav_state_msg->velocity_W.y  = gController.lqr_identification_U.X[4];
    uav_state_msg->velocity_W.z  = gController.lqr_identification_U.X[5];
    uav_state_msg->euler_angle.x = gController.lqr_identification_U.X[6];
    uav_state_msg->euler_angle.y = gController.lqr_identification_U.X[7];
    uav_state_msg->euler_angle.z = gController.lqr_identification_U.X[8];
    uav_state_msg->euler_rate.x  = gController.lqr_identification_U.X[9];
    uav_state_msg->euler_rate.y  = gController.lqr_identification_U.X[10];
    uav_state_msg->euler_rate.z  = gController.lqr_identification_U.X[11];
    uav_state_msg->total_thrust  = gController.lqr_identification_Y.virtual_control[0];
    uav_state_msg->moment.x      = gController.lqr_identification_Y.virtual_control[1];
    uav_state_msg->moment.y      = gController.lqr_identification_Y.virtual_control[2];
    uav_state_msg->moment.z      = gController.lqr_identification_Y.virtual_control[3];

    uav_state_msg->header.stamp  =  ros::Time::now();
    uav_state_pub_.publish(uav_state_msg);

    ros::spinOnce();
    r.sleep();
  }
  gController.terminate();

  return 0;
}