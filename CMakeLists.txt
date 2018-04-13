cmake_minimum_required(VERSION 2.8.3)
project(homework1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  roscpp
  sensor_msgs
  std_msgs
  message_generation
)

add_message_files(
  FILES
  data.msg
  select.msg
)

generate_messages(
  DEPENDENCIES
)

catkin_package()

include_directories(
  src/
  ${catkin_INCLUDE_DIRS}
)

set(SRCSP src/publisher.cpp)
set(SRCSR src/receiver.cpp)
set(SRCSS src/selector.cpp)

add_executable(publisher ${SRCSP})
add_executable(receiver ${SRCSR})
add_executable(selector ${SRCSS})

target_link_libraries(publisher
  ${catkin_LIBRARIES}
)

target_link_libraries(receiver
  ${catkin_LIBRARIES}
)

target_link_libraries(selector
  ${catkin_LIBRARIES}
)
