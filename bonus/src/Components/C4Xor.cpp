/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Xor
*/

#include "C4Xor.hpp"
#include "Tristate.hpp"

nts::C4Xor::C4Xor(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AGateComponent(pos, font, name, operator^) {}
