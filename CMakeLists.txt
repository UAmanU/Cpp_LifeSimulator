cmake_minimum_required(VERSION 3.20)
project(Cpp_LifeSimulator LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

file(GLOB_RECURSE LIFE_SIMULATOR_CPP CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.cpp"
)

add_executable(Cpp_LifeSimulator
    ${LIFE_SIMULATOR_CPP}
    "${CMAKE_CURRENT_SOURCE_DIR}/Lib/sqlite3.c"
)
target_include_directories(Cpp_LifeSimulator
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Include/Storage"
    "${CMAKE_CURRENT_SOURCE_DIR}/Lib/")