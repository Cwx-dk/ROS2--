#创建工作空间
mkdir -p demo01_ws/src

cd demo01_ws

##编译
colcon build

source ./install/setup.bash

cd src

##创建功能包

ros2 pkg create topic_cpp --build-type ament_cmake --dependencies rclcpp 

colcon build

source ./install/setup.bash

———————————————————————————————————————

#启动命令

colcon build

source ./devel/setup.bash

ros2 run 功能包名 节点文件名

#说明
topic_publisher、topic_subscriber 为话题通信示例

turtle_server、turtle_client 为服务通信的订阅乌龟坐标示例

turtle_chase为龟追龟代码

以上均为C++代码
