cmake_minimum_required(VERSION 3.29)

project(glfw-vulkan-opengl)

set(main_path src/main-vulkan.cpp)

add_executable(${PROJECT_NAME} ${main_path})

add_library(glad STATIC IMPORTED)
add_library(vulkan STATIC IMPORTED)
add_library(glfw STATIC IMPORTED)

set_property(TARGET glad PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/dependencies/bin/glad/libglad.a)
set_property(TARGET vulkan PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/dependencies/bin/vulkan/vulkan-1.lib)
set_property(TARGET glfw PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/dependencies/bin/GLFW/libglfw3.a)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/include/)

target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} vulkan)
target_link_libraries(${PROJECT_NAME} glfw)