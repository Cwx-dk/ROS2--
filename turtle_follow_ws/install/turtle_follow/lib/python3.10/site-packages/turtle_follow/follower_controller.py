import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class FollowerController(Node):

    def __init__(self):
        super().__init__('follower_controller')
        self.spawn_turtle2()
        
        self.leader_pose = None
        self.follower_pose = None

        # 订阅领导者（turtle1）和跟随者（turtle2）的位姿
        self.leader_pose_sub = self.create_subscription(
            Pose,
            '/turtle1/pose',
            self.leader_pose_callback,
            10)
        self.follower_pose_sub = self.create_subscription(
            Pose,
            '/turtle2/pose',
            self.follower_pose_callback,
            10)

        # 创建发布器控制turtle2的速度
        self.cmd_vel_pub = self.create_publisher(Twist, '/turtle2/cmd_vel', 10)
        
        # 创建定时器控制循环
        self.timer = self.create_timer(0.1, self.control_callback)

    def spawn_turtle2(self):
        client = self.create_client(Spawn, 'spawn')
        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('等待spawn服务...')

        req = Spawn.Request()
        req.x = 5.0
        req.y = 5.0
        req.theta = 0.0
        req.name = 'turtle2'
        
        future = client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info(f'乌龟 {future.result().name} 生成成功')
        else:
            self.get_logger().error('生成乌龟失败')

    def leader_pose_callback(self, msg):
        self.leader_pose = msg

    def follower_pose_callback(self, msg):
        self.follower_pose = msg

    def control_callback(self):
        if None in (self.leader_pose, self.follower_pose):
            return

        # 计算位置差
        dx = self.leader_pose.x - self.follower_pose.x
        dy = self.leader_pose.y - self.follower_pose.y
        distance = math.hypot(dx, dy)
        
        # 计算目标角度
        target_angle = math.atan2(dy, dx)
        angle_diff = target_angle - self.follower_pose.theta
        
        # 角度归一化到[-π, π]
        angle_diff = math.atan2(math.sin(angle_diff), math.cos(angle_diff))

        cmd_vel = Twist()
        
        # 距离控制
        safe_distance = 1.5
        if distance > safe_distance:
            cmd_vel.linear.x = 1.5  # 最大线速度
        else:
            cmd_vel.linear.x = 0.0

        # 角度控制
        cmd_vel.angular.z = angle_diff * 2.0  # 调整转向灵敏度

        self.cmd_vel_pub.publish(cmd_vel)

def main(args=None):
    rclpy.init(args=args)
    controller = FollowerController()
    rclpy.spin(controller)
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
