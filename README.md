#创建工作空间
mkdir -p demo01_ws/src
cd demo01_ws
#编译
colcon build
source ./install/setup.bash
cd src
创建功能包
ros2 pkg create topic_cpp --build-type ament_cmake --dependencies rclcpp 
colcon build
source ./install/setup.bash

#启动命令
ros2 run 功能包名 节点文件名


