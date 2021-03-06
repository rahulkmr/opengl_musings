cmake_minimum_required (VERSION 3.10)

project(opengl-musings)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(assimp REQUIRED)
include_directories(
    ${OPENGL_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)


add_library(glad src/glad.c)
add_library(utils src/utils.cpp)

add_executable(hello_window src/hello_window.cpp)
target_link_libraries(
    hello_window ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(triangle src/triangle.cpp)
target_link_libraries(
    triangle ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(rectangle src/rectangle.cpp)
target_link_libraries(
    rectangle ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(changing_color src/changing_color.cpp)
target_link_libraries(
    changing_color ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(position_and_color src/position_and_color.cpp)
target_link_libraries(
    position_and_color ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(texture src/texture.cpp)
target_link_libraries(
    texture ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(transform src/transform.cpp)
target_link_libraries(
    transform ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(coordinates src/coordinates.cpp)
target_link_libraries(
    coordinates ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(rotating src/rotating.cpp)
target_link_libraries(
    rotating ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(more_cubes src/more_cubes.cpp)
target_link_libraries(
    more_cubes ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(rotate_camera src/rotate_camera.cpp)
target_link_libraries(
    rotate_camera ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(walk_around src/walk_around.cpp)
target_link_libraries(
    walk_around ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(camera_walk_around src/camera_walk_around.cpp)
target_link_libraries(
    camera_walk_around ${OPENGL_LIBRARIES} glfw glad utils
)

add_executable(lighting src/lighting.cpp)
target_link_libraries(
    lighting ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(material src/material.cpp)
target_link_libraries(
    material ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(maps src/maps.cpp)
target_link_libraries(
    maps ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(directional src/directional.cpp)
target_link_libraries(
    directional ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(point_light src/point_light.cpp)
target_link_libraries(
    point_light ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(multiple_lights src/multiple_lights.cpp)
target_link_libraries(
    multiple_lights ${OPENGL_LIBRARIES} glfw glad utils
)


add_executable(load_model src/load_model.cpp)
target_link_libraries(
    load_model ${OPENGL_LIBRARIES} glfw glad ${ASSIMP_LIBRARIES}
)


add_executable(cubemap src/cubemap.cpp)
target_link_libraries(
    cubemap ${OPENGL_LIBRARIES} glfw glad
)


add_executable(stencil src/stencil.cpp)
target_link_libraries(
    stencil ${OPENGL_LIBRARIES} glfw glad
)


add_executable(discard src/discard.cpp)
target_link_libraries(
    discard ${OPENGL_LIBRARIES} glfw glad
)


add_executable(blending src/blending.cpp)
target_link_libraries(
    blending ${OPENGL_LIBRARIES} glfw glad
)


add_executable(framebuffer src/framebuffer.cpp)
target_link_libraries(
    framebuffer ${OPENGL_LIBRARIES} glfw glad
)


add_executable(explode src/explode.cpp)
target_link_libraries(
    explode ${OPENGL_LIBRARIES} glfw glad ${ASSIMP_LIBRARIES}
)


add_executable(instancing src/instancing.cpp)
target_link_libraries(
    instancing ${OPENGL_LIBRARIES} glfw glad
)