/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Main
*/

#include <iostream>
#include <memory>
#include <map>
#include "Input.hpp"
#include "ComponentFactory.hpp"
#include "NanoTekSpice.hpp"
#include "Parsing.hpp"
#include "Shell.hpp"

#include "Input.hpp"

int main(int ac, char **av)
{
    if (ac != NBARGS)
        return EPIERROR;
    try {
        std::string filename = av[1];
        nts::Shell shell;
        nts::Parsing parser(filename, shell.getMap());
        parser.parseFile();
        shell.run();
    } catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EPIERROR;
    }
    return EPISUCCESS;
}