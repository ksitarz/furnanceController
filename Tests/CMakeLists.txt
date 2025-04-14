cmake_minimum_required(VERSION 3.10)
project(unit_tests C)

# Główne ścieżki do źródeł i nagłówków z projektu
set(SRC_DIR "${CMAKE_SOURCE_DIR}/../Core/Src")
set(INC_DIR "${CMAKE_SOURCE_DIR}/../Core/Inc")

# Unity
set(UNITY_DIR "${CMAKE_SOURCE_DIR}/lib/Unity/src")

# Dodaj ścieżki do nagłówków
include_directories(
    ${INC_DIR}
    ${UNITY_DIR}
)

# Pliki źródłowe
set(SOURCES
    test_controller.c
    ${SRC_DIR}/controller.c
	${SRC_DIR}/config.c 
    ${UNITY_DIR}/unity.c
)

# Tworzenie pliku wykonywalnego
add_executable(test_controller ${SOURCES})
