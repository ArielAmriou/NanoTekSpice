cmake_minimum_required(VERSION 3.0)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

set(MAIN
    src/Main.cpp
)

set(SRCS
    src/Parsing.cpp
)

set(HEADERS
    include/
)

add_executable(nanotekspice ${MAIN} ${SRCS})
target_include_directories(nanotekspice PRIVATE ${HEADERS})

find_library(CRITERION criterion REQUIRED)

set(SRCS_TESTS
    tests/tests_init.cpp
    tests/tests_parsing.cpp
)

add_executable(tests_run_bin ${SRCS_TESTS} ${SRCS})
target_include_directories(tests_run_bin PRIVATE ${HEADERS})
target_link_libraries(tests_run_bin criterion --coverage)

add_custom_target(tests_run
    COMMAND ./tests_run_bin
    DEPENDS tests_run_bin
)