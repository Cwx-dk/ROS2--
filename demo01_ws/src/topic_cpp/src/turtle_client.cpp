#include "rclcpp/rclcpp.hpp"
#include "base_interfaces_demo/srv/position.hpp"
#include <chrono>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  // 初始化ROS2节点
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("turtle_pose_client");
  
  // 创建服务客户端
  auto client = node->create_client<base_interfaces_demo::srv::Position>("get_turtle_pose");

  // 等待服务端上线
  while (!client->wait_for_service(10s) && rclcpp::ok()) {
    RCLCPP_WARN(node->get_logger(), "等待服务端上线...");
  }

  // 持续查询坐标
  while (rclcpp::ok()) {
    // 构造空请求
    auto request = std::make_shared<base_interfaces_demo::srv::Position::Request>();
    
    // 发送请求并等待响应
    auto result = client->async_send_request(request);
    if (rclcpp::spin_until_future_complete(node, result, 1s) == rclcpp::FutureReturnCode::SUCCESS) {
      // 覆盖式打印坐标
      auto resp = result.get();
      RCLCPP_INFO(node->get_logger(), "\r小乌龟坐标：x=%.2f, y=%.2f", resp->x, resp->y);
    }

    // 控制查询频率
    rclcpp::sleep_for(200ms);
  }

  // 退出
  rclcpp::shutdown();
  return 0;
}