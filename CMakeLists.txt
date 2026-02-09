cmake_minimum_required(VERSION 3.0)

project(NanoTekSpice)

# Crée des variables avec les fichiers à compiler
set(SRCS
    src/Main.cpp
    )

set(SRCS_TESTS
    tests/tests_init.cpp
    )
    
set(HEADERS
    include/NanoTekSpice.hpp
    )

add_executable(NanoTekSpice ${SRCS} ${HEADERS})

add_executable(tests_run ${SRCS_TESTS})
target_link_libraries(tests_run criterion)
add_test(NAME tests_run COMMAND tests_run)
