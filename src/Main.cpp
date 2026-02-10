/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Main
*/

#include <iostream>
#include "NanoTekSpice.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    if (ac != NBARGS)
    return EPIERROR;
    try {
        nts::Parsing parser;
        std::string filename = av[1];
        parser.parsing(filename);
    } catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EPIERROR;
    }
    return EPISUCCESS;
}