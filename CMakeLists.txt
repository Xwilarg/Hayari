cmake_minimum_required(VERSION 3.10)
project(Hayari)

SET(CMAKE_CXX_FLAGS "/W4 /EHsc")

find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

include_directories(./inc/)
aux_source_directory(./src SRCS)

add_executable(Hayari ${SRCS})

target_link_libraries(Hayari PRIVATE SDL2::SDL2 imgui::imgui)