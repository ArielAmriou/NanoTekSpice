/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CFalse
*/

#include "CFalse.hpp"

nts::CFalse::CFalse(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CFALSEX, CFALSEY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}


void nts::CFalse::simulateComponent() {};

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CFalse::_defaultPins = {
    {nts::Mode::OutputMode, {CFALSEX - SIDEOFFSET, CFALSEY / 2}, "q", nts::False}
};
