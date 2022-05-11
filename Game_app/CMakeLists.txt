cmake_minimum_required(VERSION 3.21)
project(Game_app)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Game_app sfml-graphics sfml-audio)

add_executable(Game_app main.cpp)
add_executable(Bullet Bullet.cpp Bullet.h)
add_executable(Enemy Enemy.cpp Enemy.h)
add_executable(Game Game.cpp Game.h)
add_executable(Player Player.cpp Player.h)
