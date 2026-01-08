cmake_minimum_required(VERSION 3.10)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 17)

# Исходные файлы
set(SOURCES
        main.cpp
        Game.cpp
        Player.cpp
        Utils.cpp
        )

# Исполняемый файл
add_executable(RPSLS ${SOURCES})