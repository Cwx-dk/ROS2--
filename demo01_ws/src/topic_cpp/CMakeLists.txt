cmake_minimum_required(VERSION 3.8)
project(topic_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. 查找所有依赖（含接口包+小乌龟）
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(base_interfaces_demo REQUIRED)  # 依赖自定义接口包


add_executable(topic_publisher src/topic_publisher.cpp)
ament_target_dependencies(topic_publisher
  rclcpp
  std_msgs
)


add_executable(topic_subscriber src/topic_subscriber.cpp)
ament_target_dependencies(topic_subscriber
  rclcpp
  std_msgs
)

add_executable(turtle_server src/turtle_server.cpp)
ament_target_dependencies(turtle_server
  rclcpp
  turtlesim
  base_interfaces_demo  # 关联自定义srv接口
)

add_executable(turtle_client src/turtle_client.cpp)
ament_target_dependencies(turtle_client
  rclcpp
  turtlesim
  base_interfaces_demo  # 关联自定义srv接口
)

add_executable(turtle_chase src/turtle_chase.cpp)
ament_target_dependencies(turtle_chase 
rclcpp 
geometry_msgs 
turtlesim
)

# 6. 安装所有可执行文件（支持ros2 run调用）
install(TARGETS
  topic_publisher
  topic_subscriber
  turtle_server
  turtle_client
  turtle_chase
  DESTINATION lib/${PROJECT_NAME}
)

# 7. 测试配置（保留默认）
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()