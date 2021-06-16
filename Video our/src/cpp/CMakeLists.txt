cmake_minimum_required(VERSION 3.5)
project(cpp)

if(NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif()
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

find_package(OpenCV REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)


#add_library(${PROJECT_NAME}
add_library(cpp STATIC
        src/video_transmitter.cpp
        src/video_receiver.cpp
        src/base_exception.cpp
        )

target_include_directories(cpp
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

#find_package(ament_cmake REQUIRED)


#target_link_libraries(cpp ${OpenCV_LIBS} ament_cmake)


ament_target_dependencies(cpp
        "OpenCV"
        )


install(
        DIRECTORY include/
        DESTINATION include
)

install(
        TARGETS cpp
        EXPORT export_${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        #INCLUDES DESTINATION include
)


add_executable(video_transmitter src/video_transmitter.cpp)
target_include_directories(video_transmitter PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
target_link_libraries(video_transmitter cpp)
target_compile_options(video_transmitter PRIVATE -Werror)


add_executable(video_receiver src/video_receiver.cpp)
target_include_directories(video_receiver PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
target_link_libraries(video_receiver cpp)
target_compile_options(video_receiver PRIVATE -Werror)

install(TARGETS video_transmitter video_receiver
        EXPORT export_${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME})


ament_export_include_directories(
        include
)
ament_export_targets(
        export_${PROJECT_NAME}
)
ament_export_libraries(
        cpp
)




ament_package()