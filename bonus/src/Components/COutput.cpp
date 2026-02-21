/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** COutput
*/

#include "COutput.hpp"

nts::COutput::COutput(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {50, 50}, font) {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::COutput::simulateComponent() {};

const std::vector<nts::Pin> nts::COutput::_defaultPins = {
    {nts::Mode::InputMode, {10, 25}}
};
