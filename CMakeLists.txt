cmake_minimum_required(VERSION 3.0)
project(ffmpegApp1)

#set variables and it's corresponding values
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") 
set(SOURCE_FILES  
    src/main.cpp
)

#tells CmakeLists.txt where to look for cmake files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#produce the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(FFmpeg REQUIRED)

# find_package(glfw3 3.3 REQUIRED)
# target_link_libraries(myapp glfw)
# find_package(OpenGL REQUIRED)
# target_link_libraries(myapp OpenGL::GL)

#arguments for target_link_libraries method
#   the excutable your linking into
#   link interface mode
#   libary your linking in to the extecutable

#use the find_GLFW cmake in this cmake lists
# include(FindPkgConfig)
# find_package(GLFW REQUIRED)

# #include other cmake files

include_directories(${FFMPEG_AVCODEC_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC 
    ${FFMPEG_LIBAVCODECs} 
    ${FFMPEG_LIBAVFORMAT} 
    ${FFMPEG_LIBAVUTIL} 
    )