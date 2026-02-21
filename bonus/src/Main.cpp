/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Main
*/

#include <iostream>
#include "Sfml.hpp"
#include "NtsException.hpp"

int main()
{
    try {
        nts::Sfml sfml;
        sfml.run();
    } catch (nts::FontsException &e) {
        std::cerr << e.what() << std::endl;
        return nts::EPIERROR;
    }
    return nts::EPISUCCESS;
}