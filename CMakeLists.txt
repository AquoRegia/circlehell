cmake_minimum_required(VERSION 3.20)
project(CIRCLE_HELL)

set(CMAKE_C_STANDARD 11)



add_executable(circle_hell2 "main.c" "listofcirc.c" "listofcirc.h" "framedrawer.c" "include/raygui.h")

target_include_directories(circle_hell2 PUBLIC ${PROJECT_SOURCE_DIR}/include)
find_library(RAYLIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib.a)
target_link_libraries(circle_hell2 ${PROJECT_SOURCE_DIR}/lib/libraylib.a)

if(WIN32)
    target_link_libraries(circle_hell2 m winmm gdi32)
elseif(APPLE)
    target_link_libraries(circle_hell2 m)
elseif(UNIX)
    target_link_libraries(circle_hell2 m pthread dl)
endif()