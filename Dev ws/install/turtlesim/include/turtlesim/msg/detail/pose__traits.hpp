// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM__MSG__DETAIL__POSE__TRAITS_HPP_
#define TURTLESIM__MSG__DETAIL__POSE__TRAITS_HPP_

#include "turtlesim/msg/detail/pose__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlesim::msg::Pose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: linear_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_velocity: ";
    value_to_yaml(msg.linear_velocity, out);
    out << "\n";
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity: ";
    value_to_yaml(msg.angular_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlesim::msg::Pose & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlesim::msg::Pose>()
{
  return "turtlesim::msg::Pose";
}

template<>
inline const char * name<turtlesim::msg::Pose>()
{
  return "turtlesim/msg/Pose";
}

template<>
struct has_fixed_size<turtlesim::msg::Pose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim::msg::Pose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim::msg::Pose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM__MSG__DETAIL__POSE__TRAITS_HPP_
