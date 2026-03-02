/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C6Not
*/

#include "C6Not.hpp"

nts::C6Not::C6Not(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {C6NOTX, C6NOTY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}

void nts::C6Not::simulateComponent() {
    this->_pins[1].setValue(!this->_pins[0].getValue());
    this->_pins[3].setValue(!this->_pins[2].getValue());
    this->_pins[5].setValue(!this->_pins[4].getValue());
    this->_pins[7].setValue(!this->_pins[8].getValue());
    this->_pins[9].setValue(!this->_pins[10].getValue());
    this->_pins[11].setValue(!this->_pins[12].getValue());
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::C6Not::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, C6NOTY / 7}, "D1", nts::Undefined},
    {nts::Mode::OutputMode, {C6NOTX - SIDEOFFSET, C6NOTY / 7}, "Q1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C6NOTY / 7 * 2}, "D2", nts::Undefined},
    {nts::Mode::OutputMode, {C6NOTX - SIDEOFFSET, C6NOTY / 7 * 2}, "Q2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C6NOTY / 7 * 3}, "D3", nts::Undefined},
    {nts::Mode::OutputMode, {C6NOTX - SIDEOFFSET, C6NOTY / 7 * 3}, "Q3", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VSS", nts::Undefined},
    {nts::Mode::OutputMode, {C6NOTX - SIDEOFFSET, C6NOTY / 7 * 4}, "Q4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C6NOTY / 7 * 4}, "D4", nts::Undefined},
    {nts::Mode::OutputMode, {C6NOTX - SIDEOFFSET, C6NOTY / 7 * 5}, "Q5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C6NOTY / 7 * 5}, "D5", nts::Undefined},
    {nts::Mode::OutputMode, {C6NOTX - SIDEOFFSET, C6NOTY / 7 * 6}, "Q6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C6NOTY / 7 * 6}, "D6", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VDD", nts::Undefined},
};
