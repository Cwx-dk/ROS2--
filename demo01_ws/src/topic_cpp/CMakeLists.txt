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
find_package(base_interfaces_demo REQUIRED)  # 依赖自定义接口包

# 2. 编译发布者（若后续用接口，需补充链接，当前仅基础配置）
add_executable(topic_publisher src/topic_publisher.cpp)
ament_target_dependencies(topic_publisher
  rclcpp
  std_msgs
  # 若发布者用到自定义接口，添加：base_interfaces_demo
)

# 3. 编译订阅者（同发布者，按需补充接口依赖）
add_executable(topic_subscriber src/topic_subscriber.cpp)
ament_target_dependencies(topic_subscriber
  rclcpp
  std_msgs
  # 若订阅者用到自定义接口，添加：base_interfaces_demo
)

# 4. 编译小乌龟服务端（核心：依赖自定义接口+链接接口库）
add_executable(turtle_server src/turtle_server.cpp)
ament_target_dependencies(turtle_server
  rclcpp
  turtlesim
  base_interfaces_demo  # 关联自定义srv接口
)

# 5. 编译小乌龟客户端（核心：依赖自定义接口+链接接口库）
add_executable(turtle_client src/turtle_client.cpp)
ament_target_dependencies(turtle_client
  rclcpp
  turtlesim
  base_interfaces_demo  # 关联自定义srv接口
)
# 6. 安装所有可执行文件（支持ros2 run调用）
install(TARGETS
  topic_publisher
  topic_subscriber
  turtle_server
  turtle_client
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