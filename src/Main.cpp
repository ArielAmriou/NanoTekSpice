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

int main(int ac, char **av)
{
    //std::unique_ptr<nts::IComponent> a = nts::ComponentFactory::createComponent("input");
    //a->getPinMode(0);
    if (ac != NBARGS)
    return EPIERROR;
    try {
        std::map<std::string, std::unique_ptr<nts::IComponent>> map;
        nts::Parsing parser;
        std::string filename = av[1];
        parser.parsing(filename, map);
    } catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EPIERROR;
    }
    return EPISUCCESS;
}