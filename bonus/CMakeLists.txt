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
    src/AButton.cpp
    src/ComponentButton.cpp
    src/RightToolBar.cpp
    src/Slider.cpp
    src/Variables.cpp
    src/TristateButton.cpp
    src/ChangeState.cpp
    src/SimulateButton.cpp
    src/SimulateToolBar.cpp
    src/Parsing.cpp
    src/Save.cpp

    src/Components/AComponent.cpp
    src/Components/ABasicComponent.cpp
    src/Components/AGateComponent.cpp
    src/Components/CInput.cpp
    src/Components/COutput.cpp
    src/Components/CClock.cpp
    src/Components/CTrue.cpp
    src/Components/CFalse.cpp
    src/Components/CAnd.cpp
    src/Components/CNot.cpp
    src/Components/COr.cpp
    src/Components/CXor.cpp
    src/Components/CLogger.cpp
    src/Components/C4And.cpp
    src/Components/C4Nand.cpp
    src/Components/C4Or.cpp
    src/Components/C4Nor.cpp
    src/Components/C4Xor.cpp
    src/Components/CRom.cpp
    src/Components/CRam.cpp
    src/Components/CCounter.cpp
    src/Components/C6Not.cpp
    src/Components/C7Seg.cpp
    src/Components/CMatrix.cpp
    src/Components/CPictures.cpp
    src/Components/CJohnson.cpp
)

set(HEADERS
    include/
    include/Components
)

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

add_executable(bonus ${MAIN} ${SRCS})
target_include_directories(bonus PRIVATE ${HEADERS})
target_compile_options(bonus PRIVATE -g3)
target_link_libraries(bonus sfml-graphics sfml-window sfml-system)
