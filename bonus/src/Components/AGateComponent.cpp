/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** AGateComponent
*/

#include "AGateComponent.hpp"

nts::AGateComponent::AGateComponent(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {AGATECOMPONENTX, AGATECOMPONENTY}, font, _defaultPins)
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
