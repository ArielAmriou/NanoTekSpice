/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4And
*/

#include "C4And.hpp"
#include "Tristate.hpp"

nts::C4And::C4And(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AGateComponent(pos, font, name, operator&) {}
