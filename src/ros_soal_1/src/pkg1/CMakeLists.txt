cmake_minimum_required(VERSION 3.8)
project(pkg1) 

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


add_executable(sensor_node src/sensor_node.cpp)
ament_target_dependencies(sensor_node rclcpp std_msgs)


# This installs your python script as a runnable program
install(PROGRAMS
  scripts/alarm_node.py
  DESTINATION lib/${PROJECT_NAME}
)

# --- THE INSTALL PART ---
install(TARGETS
  sensor_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()