cmake_minimum_required(VERSION 3.5)

project(santa_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(SDL2_LIBRARY         SDL2)
find_library(SDL2_IMAGE_LIBRARY   SDL2_image)

add_executable(santa_game      main.cpp
                               buffer.cpp
                               buffer.hpp
                               game.cpp
                               game.hpp
                               level.cpp
                               level.hpp
                               object.cpp
                               object.hpp
                               render.hpp
                               render.cpp
                               window.cpp
                               window.hpp
                               )

target_link_libraries(santa_game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
