cmake_minimum_required(VERSION 3.5)
project(geus)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/sprite.h src/sprite.cpp src/engine.h src/engine.cpp src/bullet.h src/bullet.cpp src/player.h src/player.cpp src/custom_ncurses.h src/geus.h src/geus.cpp src/colors.h src/colors.cpp src/enemy.h src/enemy.cpp src/bullet_fast.h src/bullet_fast.cpp src/bullet_huge.h src/bullet_huge.cpp src/power_ups.h src/power_ups.cpp)
add_executable(geus ${SOURCE_FILES})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
link_directories(${CURSES_LIBRARY_DIRS})
target_link_libraries(geus ${CURSES_LIBRARIES})
