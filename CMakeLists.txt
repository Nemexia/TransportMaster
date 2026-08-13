cmake_minimum_required(VERSION 4.3)
project(TransportMaster VERSION 0.1.0 LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(TransportMaster src/main.cpp
        src/application/application.cpp
        src/application/application.hpp
)

find_package(raylib CONFIG REQUIRED)

target_link_libraries(
        TransportMaster
        PRIVATE
        raylib
)
