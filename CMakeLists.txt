cmake_minimum_required(VERSION 3.5)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN
    src/Main.cpp
)

set(SRCS
    src/Parsing.cpp
    src/ComponentFactory.cpp
    src/Components/AComponent.cpp
    src/Components/CInput.cpp
    src/Components/COutput.cpp
    src/Components/CTrue.cpp
    src/Components/CFalse.cpp
    src/Components/CClock.cpp
    src/Components/CNot.cpp
    src/Components/CAnd.cpp
    src/Components/COr.cpp
    src/Components/CXor.cpp
    src/Components/C6Not.cpp
    src/Components/C4And.cpp
    src/Components/C4Or.cpp
    src/Components/C4Xor.cpp
    src/Components/C4Nor.cpp
    src/Components/C4Nand.cpp
    src/Components/CAdder.cpp
    src/Components/CCounter.cpp
    src/Components/CLogger.cpp
    src/Components/CSelector.cpp
    src/Components/CDecoder.cpp
    src/Shell.cpp
    src/Tristate.cpp
    src/Pin.cpp
    src/Utils.cpp
)

set(HEADERS
    include/
    include/components
)

add_executable(nanotekspice ${MAIN} ${SRCS})
target_include_directories(nanotekspice PRIVATE ${HEADERS})

find_library(CRITERION criterion REQUIRED)

set(SRCS_TESTS
    tests/tests_init.cpp
    tests/tests_parsing.cpp
    tests/tests_component.cpp
)

add_executable(tests_run_bin EXCLUDE_FROM_ALL ${SRCS_TESTS} ${SRCS})
target_include_directories(tests_run_bin PRIVATE ${HEADERS})
target_compile_options(tests_run_bin PRIVATE --coverage)
target_link_libraries(tests_run_bin criterion --coverage)

add_custom_target(tests_run
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/*.gcda
    COMMAND ${CMAKE_COMMAND} -E rm -f log.bin
    COMMAND ./tests_run_bin
    DEPENDS tests_run_bin
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)