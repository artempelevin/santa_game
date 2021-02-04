cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)
find_library(SDL2_LIBRARY         SDL2)
find_library(SDL2_IMAGE_LIBRARY   SDL2_image)

set(GOOGLETEST_DIR ../googletest)
set(GTestFiles ${GOOGLETEST_DIR}/googletest/src/gtest-all.cc)
set(GTestIncludes ${GOOGLETEST_DIR}/googletest/ ${GOOGLETEST_DIR}/googletest/include)
set(SantaGameSrc ../src)

include_directories(${GTestIncludes} ${SantaGameSrc})


add_executable(tests      main.cpp
                          test_buffer.cpp
                          test_object.cpp

                          ../src/buffer.cpp
                          ../src/buffer.hpp
                          ../src/object.cpp
                          ../src/object.hpp
                          ../src/render.cpp
                          ../src/render.hpp
                          ${GTestFiles})

add_test(NAME test COMMAND test)
target_link_libraries(tests PRIVATE Threads::Threads ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} )


