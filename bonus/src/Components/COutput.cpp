/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** COutput
*/

#include "COutput.hpp"

nts::COutput::COutput(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {50, 50}, font, _defaultPins) {
    this->_nbPins = this->_pins.size();
}

void nts::COutput::simulateComponent() {};

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::COutput::_defaultPins = {
    {nts::Mode::InputMode, {10, 25}, "D", nts::Undefined}
};
