cmake_minimum_required(VERSION 3.5)
project(cv_pkg_msgs)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
        msg/ArucoMarkers.msg
        DEPENDENCIES
        geometry_msgs
        )

ament_package()
