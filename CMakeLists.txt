cmake_minimum_required(VERSION 3.20)
project(TradingSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(TradingSim
    src/main.cpp
    src/Event.cpp
    src/Order.cpp
)

target_include_directories(TradingSim PRIVATE include)