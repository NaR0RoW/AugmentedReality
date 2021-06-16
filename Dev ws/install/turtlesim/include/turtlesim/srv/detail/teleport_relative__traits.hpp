// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim:srv/TeleportRelative.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM__SRV__DETAIL__TELEPORT_RELATIVE__TRAITS_HPP_
#define TURTLESIM__SRV__DETAIL__TELEPORT_RELATIVE__TRAITS_HPP_

#include "turtlesim/srv/detail/teleport_relative__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlesim::srv::TeleportRelative_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear: ";
    value_to_yaml(msg.linear, out);
    out << "\n";
  }

  // member: angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular: ";
    value_to_yaml(msg.angular, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlesim::srv::TeleportRelative_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlesim::srv::TeleportRelative_Request>()
{
  return "turtlesim::srv::TeleportRelative_Request";
}

template<>
inline const char * name<turtlesim::srv::TeleportRelative_Request>()
{
  return "turtlesim/srv/TeleportRelative_Request";
}

template<>
struct has_fixed_size<turtlesim::srv::TeleportRelative_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim::srv::TeleportRelative_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim::srv::TeleportRelative_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlesim::srv::TeleportRelative_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlesim::srv::TeleportRelative_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlesim::srv::TeleportRelative_Response>()
{
  return "turtlesim::srv::TeleportRelative_Response";
}

template<>
inline const char * name<turtlesim::srv::TeleportRelative_Response>()
{
  return "turtlesim/srv/TeleportRelative_Response";
}

template<>
struct has_fixed_size<turtlesim::srv::TeleportRelative_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim::srv::TeleportRelative_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim::srv::TeleportRelative_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtlesim::srv::TeleportRelative>()
{
  return "turtlesim::srv::TeleportRelative";
}

template<>
inline const char * name<turtlesim::srv::TeleportRelative>()
{
  return "turtlesim/srv/TeleportRelative";
}

template<>
struct has_fixed_size<turtlesim::srv::TeleportRelative>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim::srv::TeleportRelative_Request>::value &&
    has_fixed_size<turtlesim::srv::TeleportRelative_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim::srv::TeleportRelative>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim::srv::TeleportRelative_Request>::value &&
    has_bounded_size<turtlesim::srv::TeleportRelative_Response>::value
  >
{
};

template<>
struct is_service<turtlesim::srv::TeleportRelative>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim::srv::TeleportRelative_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim::srv::TeleportRelative_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM__SRV__DETAIL__TELEPORT_RELATIVE__TRAITS_HPP_
