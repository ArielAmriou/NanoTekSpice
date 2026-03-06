/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** AGateComponent
*/

#include "AGateComponent.hpp"

nts::AGateComponent::AGateComponent(sf::Vector2f pos, sf::Font &font, const std::string &name, std::function<Tristate(Tristate, Tristate)> func)
    : APartComponent(name, pos, {AGATECOMPONENTX, AGATECOMPONENTY}, font, _defaultPins, GATECOMPONENTNBPART, GATECOMPONENTNBIN, GATECOMPONENTNBOUT), _func(func)
{
    this->_nbPins = this->_pins.size();
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::AGateComponent::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9}, "d1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 2}, "d2", nts::Undefined},
    {nts::Mode::OutputMode, {AGATECOMPONENTX - SIDEOFFSET, AGATECOMPONENTY / 5}, "q1", nts::Undefined},
    {nts::Mode::OutputMode, {AGATECOMPONENTX - SIDEOFFSET, AGATECOMPONENTY / 5 * 2}, "q2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 3}, "d3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 4}, "d4", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VSS", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 5}, "d5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 6}, "d6", nts::Undefined},
    {nts::Mode::OutputMode, {AGATECOMPONENTX - SIDEOFFSET, AGATECOMPONENTY / 5 * 3}, "q3", nts::Undefined},
    {nts::Mode::OutputMode, {AGATECOMPONENTX - SIDEOFFSET, AGATECOMPONENTY / 5 * 4}, "q4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 7}, "d7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, AGATECOMPONENTY / 9 * 8}, "d8", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VDD", nts::Undefined},
};

void nts::AGateComponent::computePart(std::size_t id)
{
    this->_pins[_outputs[id]].setValue(_func(
        this->_pins[_inputs[id * 2]].getValue(),
        this->_pins[_inputs[id * 2 + 1]].getValue()
    ));
}

const std::vector<std::size_t> nts::AGateComponent::_inputs = {
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8
};

const std::vector<std::size_t> nts::AGateComponent::_outputs = {
    Q1,
    Q2,
    Q3,
    Q4,
};
