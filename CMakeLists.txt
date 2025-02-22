cmake_minimum_required(VERSION 3.0)
project("CIRCLE_HELL")

set(CMAKE_C_STANDARD 11)



add_executable(circle_hell "main.c" "listofcirc.c" "listofcirc.h" "framedrawer.c" "include/raygui.h")

target_include_directories(circle_hell PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(circle_hell "${PROJECT_SOURCE_DIR}/lib/libraylib.a" winmm.lib)