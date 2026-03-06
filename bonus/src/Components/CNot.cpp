/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CNot
*/

#include "CNot.hpp"

nts::CNot::CNot(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CNOTX, CNOTY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}

void nts::CNot::simulateComponent() {
    this->_pins[1].setValue(!(this->_pins[0].getValue()));
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CNot::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CNOTY / 2}, "D", nts::Undefined},
    {nts::Mode::OutputMode, {CNOTY - SIDEOFFSET, CNOTY / 2}, "q", nts::Undefined}
};
