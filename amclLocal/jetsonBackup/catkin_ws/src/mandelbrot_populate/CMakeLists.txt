cmake_minimum_required(VERSION 3.9)
project(mandelbrot_populate)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Set CMAKE_BUILD_TYPE
set(CMAKE_BUILD_TYPE Release)
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
# For Windows, MSVC compiler disable boost autolinking
add_definitions( -DBOOST_ALL_NO_LIB )
# And force all boost libraries to link dynamically
add_definitions( -DBOOST_ALL_DYN_LINK )
if(ALIAS_ROS1_CLASS_LOADER)
    add_definitions(-Dclass_loader=ros1_class_loader)
endif()
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
)
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS
  roscpp
  sensor_msgs
  std_msgs
  INCLUDE_DIRS include
)
###########
## Build ##
###########
## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  "/codegen/exe"
  "include/mandelbrot_populate"
)
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
## Get list of .c files in project source directory
file(GLOB ${PROJECT_NAME}_C_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.c)
## Get list of .cpp files in project source directory
file(GLOB ${PROJECT_NAME}_CPP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.cpp)
# Declare executable - Node
add_executable(mandelbrot_populate
  src/Subscriber.cpp
  src/main.cpp
  src/mandelbrot_populate.cpp
  src/mandelbrot_populate_data.cpp
  src/mandelbrot_populate_initialize.cpp
  src/mandelbrot_populate_terminate.cpp
  src/ros_TimeStruct.cpp
  src/ros_structmsg_conversion.cpp
  src/sensor_msgs_LaserScanStruct.cpp
  src/std_msgs_HeaderStruct.cpp
  src/mlroscpp_sub.cpp
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#target_compile_options(mandelbrot_populate PUBLIC  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>: -Wall -Wextra -Wpedantic >)
endif()
target_compile_options(mandelbrot_populate PUBLIC 
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
  -DROS_PROJECT
  -DMW_SCHED_OTHER
  -DSTACK_SIZE=200000
  -DMODEL=mandelbrot_populate
  >
  )
## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(
  mandelbrot_populate
  ${catkin_EXPORTED_TARGETS}
)
target_include_directories(mandelbrot_populate PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
## Specify libraries to link a library or executable target against
target_link_libraries(
  mandelbrot_populate 
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    ${CMAKE_DL_LIBS}
)
install(TARGETS mandelbrot_populate
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
foreach(file_i ${CUDA_BINS})
add_custom_command(
                   TARGET mandelbrot_populate
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CATKIN_DEVEL_PREFIX}/codegen/exe/mandelbrot_populate/${file_i}
				   )
add_custom_command(
                   TARGET mandelbrot_populate
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CATKIN_DEVEL_PREFIX}/mandelbrot_populate_ert_rtw/${file_i}
				   )
endforeach(file_i)
# Generated on Tue Dec 06 20:28:46 2022
