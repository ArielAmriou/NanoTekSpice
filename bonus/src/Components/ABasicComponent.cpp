/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** ABasicComponent
*/

#include "ABasicComponent.hpp"

nts::ABasicComponent::ABasicComponent(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {ABASICCOMPONENTX, ABASICCOMPONENTY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::ABasicComponent::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, ABASICCOMPONENTY / 4}, "d1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, ABASICCOMPONENTY / 4 * 3}, "d2", nts::Undefined},
    {nts::Mode::OutputMode, {ABASICCOMPONENTX - SIDEOFFSET, ABASICCOMPONENTY / 2}, "q", nts::Undefined}
};
