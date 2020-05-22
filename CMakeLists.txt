cmake_minimum_required(VERSION 3.0)
project(ffmpegApp1 C CXX)
set(CMAKE_CXX_STANDARD 14)

#set variables and it's corresponding values
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") 
list(APPEND SOURCE_FILES
    src/main.cpp
    src/VideoReader.cpp
    src/VideoReader.hpp
)

#ignore opengl deprecation warnings
add_definitions(-DGL_SILENCE_DEPRECATION)

add_subdirectory(lib/glfw)
add_subdirectory(lib/FFmpeg)

add_executable(${PROJECT_NAME} MACOSX_BUNDLE WIN32 ${SOURCE_FILES})

if (APPLE)
    #produce the executable
    list (APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/MacOSXBundleInfo.plist.in
        ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist)

   set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
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
