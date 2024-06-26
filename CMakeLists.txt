cmake_minimum_required(VERSION 2.8.3)
project(gsft_control)

## Compile as C++11, supported in ROS Kinetic and newer
## add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    dynamic_reconfigure
    mav_msgs
    asctec_hl_comm
    nav_msgs
    sensor_msgs
    cmake_modules
    roscpp
    geometry_msgs
    trajectory_msgs
    message_generation
    std_msgs
    geometry_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
find_package(Eigen3 REQUIRED)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  LOE.msg
  UAVState.msg
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
 DEPENDENCIES
 std_msgs  # Or other packages containing msgs
 geometry_msgs
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
generate_dynamic_reconfigure_options(
  cfg/controllerDyn.cfg
  cfg/controllerGS1Dyn.cfg
  cfg/controllerGS2Dyn.cfg
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
    INCLUDE_DIRS include
##    LIBRARIES gsft_control
    CATKIN_DEPENDS dynamic_reconfigure geometry_msgs mav_msgs nav_msgs roscpp sensor_msgs trajectory_msgs message_generation std_msgs geometry_msgs asctec_hl_comm
    DEPENDS EIGEN3
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
 R2017a/extern/include
 R2017a/simulink/include
 src/tuning_nominal_grt_rtw/
 src/tuning_GS1_grt_rtw/
 src/tuning_GS2_grt_rtw/
 ${catkin_INCLUDE_DIRS}
 ${EIGEN3_INCLUDE_DIRS}
)

add_library(matlab_simulink

  src/tuning_nominal_grt_rtw/tuning_nominal_data.cpp
  src/tuning_nominal_grt_rtw/tuning_nominal.cpp

  src/tuning_GS1_grt_rtw/tuning_GS1_data.cpp
  src/tuning_GS1_grt_rtw/tuning_GS1.cpp

  src/tuning_GS2_grt_rtw/tuning_GS2_data.cpp
  src/tuning_GS2_grt_rtw/tuning_GS2.cpp

  #src/tuning_GS1_grt_rtw/rtGetInf.cpp
  #src/tuning_GS1_grt_rtw/rtGetNaN.cpp
  #src/tuning_GS1_grt_rtw/rt_nonfinite.cpp

)
add_dependencies(matlab_simulink ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide

add_executable(tuning_nominal_node
    src/tuning_nominal_node.cpp
)
add_dependencies(tuning_nominal_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
    matlab_simulink
)
target_link_libraries(tuning_nominal_node
    matlab_simulink
    ${catkin_LIBRARIES}
)

add_executable(tuning_GS1_node
    src/tuning_GS1_node.cpp
)
add_dependencies(tuning_GS1_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
    matlab_simulink
)
target_link_libraries(tuning_GS1_node
    matlab_simulink
    ${catkin_LIBRARIES}
)

add_executable(tuning_GS2_node
    src/tuning_GS2_node.cpp
)
add_dependencies(tuning_GS2_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
    matlab_simulink
)
target_link_libraries(tuning_GS2_node
    matlab_simulink
    ${catkin_LIBRARIES}
)
#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_gsft_control.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
