// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from base_interfaces_demo:srv/Position.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__TRAITS_HPP_
#define BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "base_interfaces_demo/srv/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace base_interfaces_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const Position_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace base_interfaces_demo

namespace rosidl_generator_traits
{

[[deprecated("use base_interfaces_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const base_interfaces_demo::srv::Position_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  base_interfaces_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use base_interfaces_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const base_interfaces_demo::srv::Position_Request & msg)
{
  return base_interfaces_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<base_interfaces_demo::srv::Position_Request>()
{
  return "base_interfaces_demo::srv::Position_Request";
}

template<>
inline const char * name<base_interfaces_demo::srv::Position_Request>()
{
  return "base_interfaces_demo/srv/Position_Request";
}

template<>
struct has_fixed_size<base_interfaces_demo::srv::Position_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<base_interfaces_demo::srv::Position_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<base_interfaces_demo::srv::Position_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace base_interfaces_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const Position_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace base_interfaces_demo

namespace rosidl_generator_traits
{

[[deprecated("use base_interfaces_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const base_interfaces_demo::srv::Position_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  base_interfaces_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use base_interfaces_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const base_interfaces_demo::srv::Position_Response & msg)
{
  return base_interfaces_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<base_interfaces_demo::srv::Position_Response>()
{
  return "base_interfaces_demo::srv::Position_Response";
}

template<>
inline const char * name<base_interfaces_demo::srv::Position_Response>()
{
  return "base_interfaces_demo/srv/Position_Response";
}

template<>
struct has_fixed_size<base_interfaces_demo::srv::Position_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<base_interfaces_demo::srv::Position_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<base_interfaces_demo::srv::Position_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<base_interfaces_demo::srv::Position>()
{
  return "base_interfaces_demo::srv::Position";
}

template<>
inline const char * name<base_interfaces_demo::srv::Position>()
{
  return "base_interfaces_demo/srv/Position";
}

template<>
struct has_fixed_size<base_interfaces_demo::srv::Position>
  : std::integral_constant<
    bool,
    has_fixed_size<base_interfaces_demo::srv::Position_Request>::value &&
    has_fixed_size<base_interfaces_demo::srv::Position_Response>::value
  >
{
};

template<>
struct has_bounded_size<base_interfaces_demo::srv::Position>
  : std::integral_constant<
    bool,
    has_bounded_size<base_interfaces_demo::srv::Position_Request>::value &&
    has_bounded_size<base_interfaces_demo::srv::Position_Response>::value
  >
{
};

template<>
struct is_service<base_interfaces_demo::srv::Position>
  : std::true_type
{
};

template<>
struct is_service_request<base_interfaces_demo::srv::Position_Request>
  : std::true_type
{
};

template<>
struct is_service_response<base_interfaces_demo::srv::Position_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__TRAITS_HPP_
