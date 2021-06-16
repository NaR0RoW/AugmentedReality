cmake_minimum_required(VERSION 3.5)
project(cv_pkg)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()



find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cv_pkg_msgs REQUIRED)




ament_export_targets(export_${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC
        cv_pkg/src/Emitter.cpp
        cv_pkg/src/Receiver.cpp
        cv_pkg/src/Receiver2.cpp
        )

ament_target_dependencies(
        ${PROJECT_NAME}
        PUBLIC
        cv_bridge
        sensor_msgs
        rclcpp
        cv_pkg_msgs
)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/include>
        $<INSTALL_INTERFACE:include>)

install(
        TARGETS ${PROJECT_NAME}
        EXPORT export_${PROJECT_NAME}
        ARCHIVE DESTINATION lib/${PROJECT_NAME}
        LIBRARY DESTINATION lib/${PROJECT_NAME}
        INCLUDES
        DESTINATION include
)


add_executable(${PROJECT_NAME}_emitter
        src/emitter_executable.cpp
        )
target_link_libraries(${PROJECT_NAME}_emitter ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_receiver
        src/receiver_executable.cpp
        )
target_link_libraries(${PROJECT_NAME}_receiver ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_receiver2
        src/receiver2_executable.cpp
        )
target_link_libraries(${PROJECT_NAME}_receiver2
        ${PROJECT_NAME}
        opencv_core
        opencv_imgproc
        opencv_highgui
        opencv_imgcodecs
        opencv_videoio
        opencv_aruco
        opencv_calib3d
        assimp
        )

add_executable(${PROJECT_NAME}_emitter_and_receiver
        src/emitter_and_receiver_executable.cpp
        )
target_link_libraries(${PROJECT_NAME}_emitter_and_receiver ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}_emitter ${PROJECT_NAME}_receiver ${PROJECT_NAME}_receiver2 ${PROJECT_NAME}_emitter_and_receiver
        EXPORT export_${PROJECT_NAME}
        RUNTIME DESTINATION lib/${PROJECT_NAME}
        )

ament_package()
