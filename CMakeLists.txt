cmake_minimum_required(VERSION 3.6)
project(Cardgames)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp card.h card.cpp deck.cpp deck.h player.cpp player.h session.cpp session.h)
add_executable(Cardgames ${SOURCE_FILES})