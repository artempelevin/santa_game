cmake_minimum_required(VERSION 3.5)

project(santa_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")

find_library(SDL2_TTF_LIBRARY     SDL2_ttf)
find_library(SDL2_LIBRARY         SDL2)
find_library(SDL2_IMAGE_LIBRARY   SDL2_image)

add_executable(santa_game      main.cpp
                               buffer.cpp
                               buffer.hpp
                               button.cpp
                               button.hpp
                               file.cpp
                               file.hpp
                               game.cpp
                               game.hpp
                               kid.cpp
                               kid.hpp
                               level.cpp
                               level.hpp
                               object.cpp
                               object.hpp
                               render.hpp
                               render.cpp
                               text.cpp
                               text.hpp
                               window.cpp
                               window.hpp
                               )

target_link_libraries(santa_game    ${SDL2_LIBRARY}
                                    ${SDL2_IMAGE_LIBRARY}
                                    ${SDL2_TTF_LIBRARY})
