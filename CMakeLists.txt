cmake_minimum_required(VERSION 3.0)
project(ffmpegApp1 C CXX)
set(CMAKE_CXX_STANDARD 14)

#set variables and it's corresponding values
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") 
set(SOURCE_FILES

    src/main.cpp
    src/VideoReader.cpp
        src/VideoReader.hpp
)

#ignore opengl deprecation warnings
add_definitions(-DGL_SILENCE_DEPRECATION)

#produce the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_subdirectory(lib/glfw)
add_subdirectory(lib/FFmpeg)

if (APPLE)
    list (APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

elseif(WIN32)
    list (APPEND EXTA_LIBS
        "-lgu32 -lopengl32")
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")
else()
    list(APPEND EXTRA_LIBS
        "-lGL -lGLU -lX11")
endif()

#included libraries
target_link_libraries(
        ${PROJECT_NAME}
        glfw
        FFmpeg
        ${EXTRA_LIBS}
)
