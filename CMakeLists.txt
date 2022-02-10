cmake_minimum_required(VERSION 3.8)

project("OpenGL_CMake_MSVC" VERSION 0.1.0)

if(MSVC)
    message("Hello MSVC!")
endif()

add_executable(main
    "src/TheMain.cpp"
    "src/GLDrawble.h"
    "src/MartrixUtil.h" "src/MatrixUtil.cpp"
    "src/CameraUtil.h" "src/CameraUtil.cpp"
    "src/MyRenderWindow.h" "src/MyRenderWindow.cpp"
    "src/Rectangle.h" "src/Rectangle.cpp"
    "src/RenderWindow.h" "src/RenderWindow.cpp"
    "src/ShaderUtil.h" "src/ShaderUtil.cpp"
    "src/TextureUtil.h" "src/TextureUtil.cpp"
)

target_include_directories(main PRIVATE include)
target_link_directories(main PRIVATE lib)
target_link_libraries(main PRIVATE glfw3dll)
# target_link_libraries(main PRIVATE glfw3dll glad -static)

set_target_properties(main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
)
