// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from base_interfaces_demo:srv/Position.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__STRUCT_H_
#define BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Position in the package base_interfaces_demo.
typedef struct base_interfaces_demo__srv__Position_Request
{
  uint8_t structure_needs_at_least_one_member;
} base_interfaces_demo__srv__Position_Request;

// Struct for a sequence of base_interfaces_demo__srv__Position_Request.
typedef struct base_interfaces_demo__srv__Position_Request__Sequence
{
  base_interfaces_demo__srv__Position_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} base_interfaces_demo__srv__Position_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Position in the package base_interfaces_demo.
typedef struct base_interfaces_demo__srv__Position_Response
{
  double x;
  double y;
} base_interfaces_demo__srv__Position_Response;

// Struct for a sequence of base_interfaces_demo__srv__Position_Response.
typedef struct base_interfaces_demo__srv__Position_Response__Sequence
{
  base_interfaces_demo__srv__Position_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} base_interfaces_demo__srv__Position_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BASE_INTERFACES_DEMO__SRV__DETAIL__POSITION__STRUCT_H_
