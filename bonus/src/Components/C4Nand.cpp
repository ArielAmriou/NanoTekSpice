/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nand
*/

#include "C4Nand.hpp"
#include "Tristate.hpp"

nts::C4Nand::C4Nand(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AGateComponent(pos, font, name, operator*) {}
