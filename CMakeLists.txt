cmake_minimum_required(VERSION 3.0)
project(Juego)

set(CMAKE_C_STANDARD 99)

add_executable(raylib_template src/main.c src/headers/player.h src/components/player.c src/headers/grid.h src/components/grid.c)
target_link_libraries(raylib_template PRIVATE raylib)
target_compile_definitions(raylib_template PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")