#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// 订阅回调函数：接收消息并打印
void topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(
        rclcpp::get_logger("topic_subscriber"), 
        "接收: '%s'", msg->data.c_str()
    );
}

int main(int argc, char * argv[])
{
    // 初始化 ROS 2
    rclcpp::init(argc, argv);

    // 创建节点（名称：topic_subscriber）
    auto node = rclcpp::Node::make_shared("topic_subscriber");

    // 创建订阅者：改为订阅发布者用的 "topic"
    auto subscription = node->create_subscription<std_msgs::msg::String>(
        "topic",   // ← 已同步修改
        10,
        topic_callback
    );

    RCLCPP_INFO(node->get_logger(), "订阅者已启动，等待接收来自 topic 的消息...");

    // 循环等待消息
    rclcpp::spin(node);

    // 关闭 ROS 2
    rclcpp::shutdown();
    return 0;
}
