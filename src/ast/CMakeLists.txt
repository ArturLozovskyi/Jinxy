add_library(jinxy.ast STATIC "")

target_include_directories(jinxy.ast PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_include_directories(jinxy.lexer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

file (GLOB_RECURSE COLLECTED_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(jinxy.ast PRIVATE ${COLLECTED_SOURCES})

# target_link_libraries(jinxy.ast PRIVATE jinxy.lexer)


