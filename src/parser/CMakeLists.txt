add_library(jinxy.parser STATIC "")

target_include_directories(jinxy.parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_include_directories(jinxy.parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

file (GLOB_RECURSE COLLECTED_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(jinxy.parser PRIVATE ${COLLECTED_SOURCES})

target_link_libraries(jinxy.parser PRIVATE jinxy.lexer)
target_link_libraries(jinxy.parser PRIVATE jinxy.ast)
