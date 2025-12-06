#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include <cmath>

class TurtleChase : public rclcpp::Node
{
public:
    TurtleChase() : Node("turtle_chase")
    {
        sub1_ = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose", 10,
            std::bind(&TurtleChase::t1_callback, this, std::placeholders::_1));

        sub2_ = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle2/pose", 10,
            std::bind(&TurtleChase::t2_callback, this, std::placeholders::_1));

        pub_ = this->create_publisher<geometry_msgs::msg::Twist>(
            "/turtle2/cmd_vel", 10);
    }

private:
    turtlesim::msg::Pose t1_, t2_;
    bool got1_ = false, got2_ = false;

    void t1_callback(const turtlesim::msg::Pose::SharedPtr msg)
    {
        t1_ = *msg;
        got1_ = true;
        chase();
    }

    void t2_callback(const turtlesim::msg::Pose::SharedPtr msg)
    {
        t2_ = *msg;
        got2_ = true;
        chase();
    }

    void chase()
    {
        if (!got1_ || !got2_) return;

        geometry_msgs::msg::Twist cmd;

        float dx = t1_.x - t2_.x;
        float dy = t1_.y - t2_.y;

        float distance = std::sqrt(dx * dx + dy * dy);
        float target_theta = std::atan2(dy, dx);

        float diff = target_theta - t2_.theta;

        // 角度归一化
        while (diff > M_PI) diff -= 2*M_PI;
        while (diff < -M_PI) diff += 2*M_PI;

        float stop_distance = 1.0;  // ≤这个距离就停

        if (distance > stop_distance)
        {
            // 远 → 追
            cmd.linear.x = 1.5;
            cmd.angular.z = diff * 2.0;
        }
        else
        {
            // 近 → 停
            cmd.linear.x = 0.0;
            cmd.angular.z = 0.0;
        }

        pub_->publish(cmd);
    }

    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub1_, sub2_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtleChase>());
    rclcpp::shutdown();
    return 0;
}
