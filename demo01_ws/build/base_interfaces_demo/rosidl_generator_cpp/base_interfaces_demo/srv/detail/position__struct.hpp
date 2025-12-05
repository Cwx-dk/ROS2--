// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from base_interfaces_demo:srv/Position.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__STRUCT_HPP_
#define BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__base_interfaces_demo__srv__Position_Request __attribute__((deprecated))
#else
# define DEPRECATED__base_interfaces_demo__srv__Position_Request __declspec(deprecated)
#endif

namespace base_interfaces_demo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Position_Request_
{
  using Type = Position_Request_<ContainerAllocator>;

  explicit Position_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Position_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    base_interfaces_demo::srv::Position_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const base_interfaces_demo::srv::Position_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      base_interfaces_demo::srv::Position_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      base_interfaces_demo::srv::Position_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__base_interfaces_demo__srv__Position_Request
    std::shared_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__base_interfaces_demo__srv__Position_Request
    std::shared_ptr<base_interfaces_demo::srv::Position_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Position_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Position_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Position_Request_

// alias to use template instance with default allocator
using Position_Request =
  base_interfaces_demo::srv::Position_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace base_interfaces_demo


#ifndef _WIN32
# define DEPRECATED__base_interfaces_demo__srv__Position_Response __attribute__((deprecated))
#else
# define DEPRECATED__base_interfaces_demo__srv__Position_Response __declspec(deprecated)
#endif

namespace base_interfaces_demo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Position_Response_
{
  using Type = Position_Response_<ContainerAllocator>;

  explicit Position_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit Position_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    base_interfaces_demo::srv::Position_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const base_interfaces_demo::srv::Position_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      base_interfaces_demo::srv::Position_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      base_interfaces_demo::srv::Position_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__base_interfaces_demo__srv__Position_Response
    std::shared_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__base_interfaces_demo__srv__Position_Response
    std::shared_ptr<base_interfaces_demo::srv::Position_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Position_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Position_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Position_Response_

// alias to use template instance with default allocator
using Position_Response =
  base_interfaces_demo::srv::Position_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace base_interfaces_demo

namespace base_interfaces_demo
{

namespace srv
{

struct Position
{
  using Request = base_interfaces_demo::srv::Position_Request;
  using Response = base_interfaces_demo::srv::Position_Response;
};

}  // namespace srv

}  // namespace base_interfaces_demo

#endif  // BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__STRUCT_HPP_
