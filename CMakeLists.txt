cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Game)

file(GLOB_RECURSE source_files "src/*.cpp")

add_executable(app ${source_files})
set_target_properties(app PROPERTIES OUTPUT_NAME "${PROJECT_SOURCE_DIR}/bin/game")

target_include_directories(app PRIVATE include)
target_include_directories(app PRIVATE raylib/src)
add_subdirectory(raylib)
target_link_directories(app PRIVATE raylib/src)
target_link_libraries(app raylib)
