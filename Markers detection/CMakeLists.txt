cmake_minimum_required(VERSION 3.15)
project( detect )
set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
find_package( OpenGL REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})




add_executable( detect detect_markers.cpp )
target_link_libraries( detect ${OpenGL_LIBS} ${GLEW_LIBRARIES} ${OpenCV_LIBS} )

