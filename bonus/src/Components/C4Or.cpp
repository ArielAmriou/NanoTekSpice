/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Or
*/

#include "C4Or.hpp"
#include "Tristate.hpp"

nts::C4Or::C4Or(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AGateComponent(pos, font, name, operator|) {}
