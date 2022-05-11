cmake_minimum_required(VERSION 3.21)
project(Game_3)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Game_3 main.cpp)
target_link_libraries(Game_3 sfml-graphics sfml-audio)

add_executable(Bullet Bullet.cpp Bullet.h)
target_link_libraries(Bullet sfml-graphics sfml-audio)
add_executable(Enemy Enemy.cpp Enemy.h)
target_link_libraries(Enemy sfml-graphics sfml-audio)
add_executable(Game Game.cpp Game.h)
target_link_libraries(Game sfml-graphics sfml-audio)
add_executable(Player Player.cpp Player.h)
target_link_libraries(Player sfml-graphics sfml-audio)
add_executable(stdafx stdafx.cpp stdafx.h)
target_link_libraries(stdafx sfml-graphics sfml-audio)
add_executable(Tile Tile.cpp Tile.h)
target_link_libraries(Tile sfml-graphics sfml-audio)
add_executable(TileMap TileMap.cpp TileMap.h)
target_link_libraries(TileMap sfml-graphics sfml-audio)


