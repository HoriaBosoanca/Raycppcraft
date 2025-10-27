cmake_minimum_required(VERSION 3.31)
project(raycppcraft)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
file(GLOB SOURCES CONFIGURE_DEPENDS
        src/*.cpp
        src/renderer/*.cpp
        src/worldgen/*.cpp
)
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib-5.5_win64_mingw-w64/include
)
target_link_libraries(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib-5.5_win64_mingw-w64/lib/libraylib.a
        winmm
)