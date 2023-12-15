cmake_minimum_required(VERSION 3.26)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

# Füge die Unterverzeichnisse für StringLib und LinkedList hinzu
add_subdirectory(StringLib)
add_subdirectory(List)

# Füge eine CombinedLib hinzu, die StringLib und LinkedList bündelt
add_library(CombinedLib INTERFACE)

# Füge StringLib und LinkedList als Abhängigkeiten für CombinedLib hinzu
target_link_libraries(CombinedLib INTERFACE StringLib List)

add_executable(LinkedList main.c)
target_link_libraries(LinkedList PRIVATE CombinedLib)