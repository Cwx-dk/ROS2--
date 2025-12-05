#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// 定义发布者节点类
class SimplePublisher : public rclcpp::Node
{
public:
    SimplePublisher() : Node("publisher_chatter"), count_(0)
    {
        // 创建发布者，话题名 "chatter"，队列大小 10
        publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
        
        // 创建定时器，1秒触发一次回调
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&SimplePublisher::timer_callback, this)
        );
        
        RCLCPP_INFO(this->get_logger(), "发布者节点已启动，开始发布消息...");
    }

private:
    // 定时器回调函数：发布消息
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = " Count: " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "发布: '%s'", message.data.c_str());
        publisher_->publish(message);
    }

    rclcpp::TimerBase::SharedPtr timer_;       // 定时器
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;  // 发布者
    size_t count_;  // 计数变量
};

int main(int argc, char * argv[])
{
    // 初始化 ROS 2
    rclcpp::init(argc, argv);
    // 运行节点
    rclcpp::spin(std::make_shared<SimplePublisher>());
    // 关闭 ROS 2
    rclcpp::shutdown();
    return 0;
}