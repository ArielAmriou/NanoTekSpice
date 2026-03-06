/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nor
*/

#include "C4Nor.hpp"

nts::C4Nor::C4Nor(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AGateComponent(pos, font, name, function) {}

const nts::Tristate nts::C4Nor::function(Tristate a, Tristate b)
{
    return !(a | b);
}