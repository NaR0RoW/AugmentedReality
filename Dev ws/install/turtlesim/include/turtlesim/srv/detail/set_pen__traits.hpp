// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim:srv/SetPen.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM__SRV__DETAIL__SET_PEN__TRAITS_HPP_
#define TURTLESIM__SRV__DETAIL__SET_PEN__TRAITS_HPP_

#include "turtlesim/srv/detail/set_pen__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlesim::srv::SetPen_Request & msg,
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

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: off
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "off: ";
    value_to_yaml(msg.off, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlesim::srv::SetPen_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlesim::srv::SetPen_Request>()
{
  return "turtlesim::srv::SetPen_Request";
}

template<>
inline const char * name<turtlesim::srv::SetPen_Request>()
{
  return "turtlesim/srv/SetPen_Request";
}

template<>
struct has_fixed_size<turtlesim::srv::SetPen_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim::srv::SetPen_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim::srv::SetPen_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const turtlesim::srv::SetPen_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const turtlesim::srv::SetPen_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<turtlesim::srv::SetPen_Response>()
{
  return "turtlesim::srv::SetPen_Response";
}

template<>
inline const char * name<turtlesim::srv::SetPen_Response>()
{
  return "turtlesim/srv/SetPen_Response";
}

template<>
struct has_fixed_size<turtlesim::srv::SetPen_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim::srv::SetPen_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim::srv::SetPen_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtlesim::srv::SetPen>()
{
  return "turtlesim::srv::SetPen";
}

template<>
inline const char * name<turtlesim::srv::SetPen>()
{
  return "turtlesim/srv/SetPen";
}

template<>
struct has_fixed_size<turtlesim::srv::SetPen>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim::srv::SetPen_Request>::value &&
    has_fixed_size<turtlesim::srv::SetPen_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim::srv::SetPen>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim::srv::SetPen_Request>::value &&
    has_bounded_size<turtlesim::srv::SetPen_Response>::value
  >
{
};

template<>
struct is_service<turtlesim::srv::SetPen>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim::srv::SetPen_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim::srv::SetPen_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM__SRV__DETAIL__SET_PEN__TRAITS_HPP_
