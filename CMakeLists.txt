cmake_minimum_required(VERSION 3.11)
project(Juego)

set(CMAKE_C_STANDARD 99)

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

add_executable(16-Bits_de_Historia src/main.c 
src/headers/player.h src/components/player.c 
src/headers/debug.h src/components/debug.c 
src/headers/level.h src/components/level.c 
src/headers/animation.h src/components/animation.c
src/headers/keybinds.h src/components/keybinds.c
src/headers/menu.h src/components/menu.c
src/headers/sound.h src/components/sound.c
src/headers/npc.h src/components/npc.c
src/headers/object.h src/components/object.c
src/headers/cine.h src/components/cine.c
src/headers/enemy.h src/components/enemy.c)

target_link_libraries(16-Bits_de_Historia PUBLIC raylib)
target_compile_definitions(16-Bits_de_Historia PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/" AUDIO_PATH="${CMAKE_CURRENT_SOURCE_DIR}/audio/")