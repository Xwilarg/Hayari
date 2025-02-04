cmake_minimum_required(VERSION 3.10)
project(Hayari)

SET(CMAKE_CXX_FLAGS "/W4 /EHsc")

find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

include_directories(./inc/ ./inc/Render ./inc/Render/Impl ./inc/Engine)

add_executable(Hayari
"src/main.cpp"
"src/Render/Impl/BuiltinRenderer.cpp"
"src/Render/Impl/DebugRenderer.cpp"
 "src/Engine/SearchEngine.cpp")

target_link_libraries(Hayari PRIVATE SDL2::SDL2 imgui::imgui)