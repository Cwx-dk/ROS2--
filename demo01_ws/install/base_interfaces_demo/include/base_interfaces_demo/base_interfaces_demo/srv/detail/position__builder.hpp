// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from base_interfaces_demo:srv/Position.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__BUILDER_HPP_
#define BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "base_interfaces_demo/srv/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace base_interfaces_demo
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::base_interfaces_demo::srv::Position_Request>()
{
  return ::base_interfaces_demo::srv::Position_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace base_interfaces_demo


namespace base_interfaces_demo
{

namespace srv
{

namespace builder
{

class Init_Position_Response_y
{
public:
  explicit Init_Position_Response_y(::base_interfaces_demo::srv::Position_Response & msg)
  : msg_(msg)
  {}
  ::base_interfaces_demo::srv::Position_Response y(::base_interfaces_demo::srv::Position_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::base_interfaces_demo::srv::Position_Response msg_;
};

class Init_Position_Response_x
{
public:
  Init_Position_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_Response_y x(::base_interfaces_demo::srv::Position_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Position_Response_y(msg_);
  }

private:
  ::base_interfaces_demo::srv::Position_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::base_interfaces_demo::srv::Position_Response>()
{
  return base_interfaces_demo::srv::builder::Init_Position_Response_x();
}

}  // namespace base_interfaces_demo

#endif  // BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__BUILDER_HPP_
