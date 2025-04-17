# CMakeLists.txt w folderze Tests/
cmake_minimum_required(VERSION 3.10)
project(UnitTests C)

# Ścieżki do źródeł i nagłówków
set(SRC_DIR "${CMAKE_SOURCE_DIR}/../Core/Src")
set(INC_DIR "${CMAKE_SOURCE_DIR}/../Core/Inc")

# Ścieżka do Unity
set(UNITY_DIR "${CMAKE_SOURCE_DIR}/Lib/Unity/src")
set(FIXTURE_DIR "${CMAKE_SOURCE_DIR}/Lib/Unity/extras/fixture/src")
set(MEMORY_DIR "${CMAKE_SOURCE_DIR}/Lib/Unity/extras/memory/src")

# Dodaj ścieżki do nagłówków
include_directories(
    ${INC_DIR}
    ${UNITY_DIR}
    ${FIXTURE_DIR}
    ${MEMORY_DIR}
)

# Pliki źródłowe
set(SOURCES
    test_controller.c
    ${SRC_DIR}/controller.c
    ${SRC_DIR}/config.c 
    ${UNITY_DIR}/unity.c
    ${FIXTURE_DIR}/unity_fixture.c
)

# Tworzenie pliku wykonywalnego
add_executable(test_controller ${SOURCES})
