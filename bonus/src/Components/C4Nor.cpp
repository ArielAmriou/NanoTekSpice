/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nor
*/

#include "C4Nor.hpp"

nts::C4Nor::C4Nor(sf::Vector2f pos, sf::Font &font, const std::string &name) : AGateComponent(pos, font, name) {}


void nts::C4Nor::simulateComponent() {
    this->_pins[2].setValue(
        !(this->_pins[0].getValue() | this->_pins[1].getValue()));
    this->_pins[3].setValue(
        !(this->_pins[4].getValue() | this->_pins[5].getValue()));
    this->_pins[9].setValue(
        !(this->_pins[7].getValue() | this->_pins[8].getValue()));
    this->_pins[10].setValue(
        !(this->_pins[11].getValue() | this->_pins[12].getValue()));
}
