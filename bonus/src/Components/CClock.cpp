/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CClock
*/

#include "CClock.hpp"

nts::CClock::CClock(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent("CLK", pos, {CCLOCKX, CCLOCKX}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}

void nts::CClock::simulateComponent() {
    auto value = this->_pins[0].getValue();
    this->_pins[0].setValue(!value);
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CClock::_defaultPins = {
    {nts::Mode::OutputMode, {CCLOCKX - SIDEOFFSET, CCLOCKY / 2}, "q", nts::Undefined}
};
