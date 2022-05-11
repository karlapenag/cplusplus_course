cmake_minimum_required(VERSION 3.21)
project(Example_App)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Example_App main.cpp)
add_executable(Game Game.cpp Game.h)
add_executable(Player Player.cpp Player.h)
add_executable(stdafx stdafx.cpp stdafx.h)
add_executable(Tile Tile.cpp Tile.h)
add_executable(TileMap TileMap.cpp TileMap.h)

target_link_libraries(Example_App sfml-graphics sfml-audio)
target_link_libraries(Game sfml-graphics sfml-audio)
target_link_libraries(Player sfml-graphics sfml-audio)
target_link_libraries(stdafx sfml-graphics sfml-audio)
target_link_libraries(Tile sfml-graphics sfml-audio)
target_link_libraries(TileMap sfml-graphics sfml-audio)
