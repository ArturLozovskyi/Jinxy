cmake_minimum_required (VERSION 3.10)

project (Jinxy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include sub-projects.
add_subdirectory (src)

add_executable(Jinxy main.cpp)

target_link_libraries(Jinxy PUBLIC jinxy.lexer)
target_link_libraries(Jinxy PUBLIC jinxy.parser)
target_link_libraries(Jinxy PUBLIC jinxy.ast)
