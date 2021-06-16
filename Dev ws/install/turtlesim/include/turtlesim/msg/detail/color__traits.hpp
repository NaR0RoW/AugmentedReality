// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim:msg/Color.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM__MSG__DETAIL__COLOR__TRAITS_HPP_
#define TURTLESIM__MSG__DETAIL__COLOR__TRAITS_HPP_

#include "turtlesim/msg/detail/color__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlesim::msg::Color & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    value_to_yaml(msg.g, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlesim::msg::Color & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlesim::msg::Color>()
{
  return "turtlesim::msg::Color";
}

template<>
inline const char * name<turtlesim::msg::Color>()
{
  return "turtlesim/msg/Color";
}

template<>
struct has_fixed_size<turtlesim::msg::Color>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim::msg::Color>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim::msg::Color>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM__MSG__DETAIL__COLOR__TRAITS_HPP_
