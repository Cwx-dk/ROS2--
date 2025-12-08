#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher() : Node("minimal_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

        auto msg = std_msgs::msg::String();
        msg.data = "Hello, world!";

        RCLCPP_INFO(this->get_logger(), "发布的消息：'%s'", msg.data.c_str());
        publisher_->publish(msg);
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    // 节点构造函数里已经发布了消息
    auto node = std::make_shared<MinimalPublisher>();

    // 让节点存在一小段时间，确保消息发布出去
    rclcpp::spin_some(node);

    rclcpp::shutdown();
    return 0;
}
