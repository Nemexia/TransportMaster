cmake_minimum_required(VERSION 4.3)

project(TrasnsportMaster)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(TransportMaster
"src/main.cpp"
)

find_package(raylib CONFIG REQUIRED)

target_link_libraries(TransportMaster PRIVATE raylib)