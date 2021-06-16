ADD_LIBRARY(stb STATIC src/stb_image.cpp)
TARGET_INCLUDE_DIRECTORIES(stb PUBLIC include)


find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)



ADD_EXECUTABLE(opengl_executable src/main.cpp)
target_link_libraries(${glfw_LIBS} opengl_executable stb ${OpenGL_LIBS} glad)
