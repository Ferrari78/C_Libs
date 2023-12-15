add_library(StringLib stringLib.c stringLib.h)

target_include_directories(StringLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link StringLib gegen LinkedList
target_link_libraries(StringLib PRIVATE List)