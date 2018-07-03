cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(velodyne_visualizer)

find_package(PCL 1.2 REQUIRED)

find_package(Boost 1.48.0 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (velodyne_visualizer velodyne_visualizer.cpp)
target_link_libraries (velodyne_visualizer ${Boost_LIBRARIES} ${PCL_LIBRARIES})
