#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// 回调函数：当收到 topic 的消息时执行
void topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    // 打印接收到的内容
    RCLCPP_INFO(
        rclcpp::get_logger("topic_subscriber"),
        "接收: '%s'", msg->data.c_str()
    );
}

int main(int argc, char * argv[])
{
    // 初始化 ROS 2
    rclcpp::init(argc, argv);

    // 创建节点，名称为 "topic_subscriber"
    auto node = rclcpp::Node::make_shared("topic_subscriber");

    // 创建订阅者：订阅 "topic"，队列长度为 10
    auto subscription = node->create_subscription<std_msgs::msg::String>(
        "topic",
        10,
        topic_callback    // 绑定回调函数
    );

    RCLCPP_INFO(node->get_logger(), "订阅者已启动，等待接收消息...");

    // 进入循环等待消息（阻塞）
    rclcpp::spin(node);

    // 关闭 ROS 2
    rclcpp::shutdown();
    return 0;
}
