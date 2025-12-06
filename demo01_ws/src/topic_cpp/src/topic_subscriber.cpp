#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// 订阅回调函数：接收消息并打印
void topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("topic_subscriber"), "接收: '%s'", msg->data.c_str());
}

int main(int argc, char * argv[])
{
    // 初始化 ROS 2
    rclcpp::init(argc, argv);
    // 创建节点（名称：topic_subscriber）
    auto node = rclcpp::Node::make_shared("topic_subscriber");
    // 创建订阅者：话题名 "chatter"，队列大小 10，绑定回调函数
    auto subscription = node->create_subscription<std_msgs::msg::String>(
        "chatter",
        10,
        topic_callback
    );

    RCLCPP_INFO(node->get_logger(), "订阅者节点已启动，等待接收消息...");
    // 循环等待消息（阻塞式，直到节点关闭）
    rclcpp::spin(node);
    // 关闭 ROS 2 上下文
    rclcpp::shutdown();
    return 0;
}