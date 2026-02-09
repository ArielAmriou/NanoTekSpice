cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_COMPILER "clang++")

project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Crée des variables avec les fichiers à compiler
set(SRCS
    src/Main.cpp
    src/Parsing.cpp
    )

set(SRCS_TESTS
    tests/tests_init.cpp
    )
    
set(HEADERS
    include/
    )


add_executable(nanotekspice ${SRCS} ${HEADERS})
target_include_directories(nanotekspice PRIVATE ${HEADERS})

add_executable(tests_run ${SRCS_TESTS})
target_link_libraries(tests_run criterion)
add_test(NAME tests_run COMMAND tests_run)
