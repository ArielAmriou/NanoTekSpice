/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C6Not
*/

#include "C6Not.hpp"

nts::C6Not::C6Not(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : APartComponent(name, pos, {C6NOTX, C6NOTY}, font, _defaultPins, C6NOTNBPART, C6NOTNBIN, C6NOTNBOUT)
{
    this->_nbPins = this->_pins.size();
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

void nts::C6Not::computePart(std::size_t id)
{
    this->_pins[_outputs[id]].setValue(
        !this->_pins[_inputs[id]].getValue());
}

const std::vector<std::size_t> nts::C6Not::_inputs = {
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
};

const std::vector<std::size_t> nts::C6Not::_outputs = {
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6
};
