cmake_minimum_required(VERSION 3.5)
project(NanoTekSpice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN
    src/Main.cpp
)

set(SRCS
    src/Sfml.cpp
    src/Event.cpp
    src/Utils.cpp
    src/Tristate.cpp
    src/Pin.cpp
    src/Connection.cpp
    src/ComponentFactory.cpp

    src/Components/AComponent.cpp
    src/Components/CInput.cpp
    src/Components/COutput.cpp
)

set(HEADERS
    include/
    include/Components
)

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

add_executable(bonus ${MAIN} ${SRCS})
target_include_directories(bonus PRIVATE ${HEADERS})
target_link_libraries(bonus sfml-graphics sfml-window sfml-system)
