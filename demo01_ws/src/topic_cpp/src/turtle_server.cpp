#include "rclcpp/rclcpp.hpp"
// 修正：引用正确的接口头文件（包名+接口名）
#include "base_interfaces_demo/srv/position.hpp"
// 小乌龟位姿消息头文件
#include "turtlesim/msg/pose.hpp"

// 全局缓存小乌龟坐标（线程安全）
std::atomic<double> turtle_x{0.0};
std::atomic<double> turtle_y{0.0};

// 订阅回调：更新小乌龟坐标
void pose_callback(const turtlesim::msg::Pose::SharedPtr msg)
{
  turtle_x = msg->x;
  turtle_y = msg->y;
}

void handle_get_turtle_pose(
  const std::shared_ptr<base_interfaces_demo::srv::Position::Request> /*request*/,  // 正确命名空间+接口名
  std::shared_ptr<base_interfaces_demo::srv::Position::Response> response)
{
  // 填充响应：返回缓存的坐标
  response->x = turtle_x;
  response->y = turtle_y;
  
  RCLCPP_INFO(rclcpp::get_logger("turtle_pose_server"), 
              "收到坐标查询请求，返回：x=%.2f, y=%.2f", response->x, response->y);
}

int main(int argc, char * argv[])
{
  // 初始化ROS2
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("turtle_pose_server");

  // 1. 订阅小乌龟位姿话题（/turtle1/pose）
  auto pose_sub = node->create_subscription<turtlesim::msg::Pose>(
    "/turtle1/pose", 10, &pose_callback);

  // 修正：创建服务端的接口类型（匹配Position.srv）
  auto service = node->create_service<base_interfaces_demo::srv::Position>(
    "get_turtle_pose", &handle_get_turtle_pose);

  RCLCPP_INFO(rclcpp::get_logger("turtle_pose_server"), 
              "小乌龟坐标查询服务已启动，等待请求...");

  // 自旋运行节点
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}