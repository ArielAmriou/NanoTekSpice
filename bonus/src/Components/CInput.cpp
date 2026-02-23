/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CInput
*/

#include "CInput.hpp"

nts::CInput::CInput(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {50, 50}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}

void nts::CInput::simulateComponent() {};

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CInput::_defaultPins = {
    {nts::Mode::OutputMode, {40, 25}, "q", nts::Undefined}
};
