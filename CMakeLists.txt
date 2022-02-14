cmake_minimum_required(VERSION 3.8)

project("OpenGL_CMake_MSVC" VERSION 0.1.0)

if(NOT MSVC)
    message(FATAL_ERROR "Can only be compiled with MSVC!")
endif()

add_compile_options("/utf-8")

add_executable(main
    # Third party
    "src/third/glad.c"
    # Main
    "src/TheMain.h" "src/TheMain.cpp"
    # Main src
    "src/base/Component.h"
    "src/base/RenderWindow.h" "src/base/RenderWindow.cpp"
    "src/base/Transform.h" "src/base/Transform.cpp"
    "src/base/GameObject.h" "src/base/GameObject.cpp"
    "src/util/MartrixUtil.h" "src/util/MatrixUtil.cpp"
    "src/util/CameraUtil.h" "src/util/CameraUtil.cpp"
    "src/util/ShaderUtil.h" "src/util/ShaderUtil.cpp"
    "src/util/TextureUtil.h" "src/util/TextureUtil.cpp"
    "src/Rectangle.h" "src/Rectangle.cpp"
    "src/MyRenderWindow.h" "src/MyRenderWindow.cpp"
)

target_include_directories(main PRIVATE include)
target_link_directories(main PRIVATE lib)
target_link_libraries(main PRIVATE glfw3dll)

set_target_properties(main
    PROPERTIES
    C_STANDARD 11
    CXX_STANDARD 17
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
)
