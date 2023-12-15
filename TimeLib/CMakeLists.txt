add_library(TimeLib timeoperations.c timeoperations.h)

target_include_directories(TimeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})