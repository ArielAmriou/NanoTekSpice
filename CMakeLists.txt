cmake_minimum_required(VERSION 3.0)

project(NanoTekSpice)

# Crée des variables avec les fichiers à compiler
set(SRCS
    src/Main.cpp
    )
    
set(HEADERS
    include/NanoTekSpice.hpp
    )

add_executable(NanoTekSpice ${SRCS} ${HEADERS})
