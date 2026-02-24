/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Main
*/

#include <iostream>
#include <filesystem>
#include "Sfml.hpp"
#include "NtsException.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    
    if (ac != 2)
        return nts::EPIERROR;
    sf::Font font;
    if (!font.loadFromFile("public/Font.ttf")) {
        std::cerr << "Error: Can't load Font file." << std::endl;
        return nts::EPIERROR;
    }
    try {
        std::filesystem::path p(av[1]);
        std::string filename = av[1];
        nts::Sfml sfml(font, p.filename());
        nts::Parsing parser(filename, sfml.getMap(), font);
        parser.parseFile();
        sfml.run();
    } catch (nts::NtsException &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return nts::EPIERROR;
    }
    return nts::EPISUCCESS;
}