/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CXor
*/

#include "CXor.hpp"

nts::CXor::CXor(sf::Vector2f pos, sf::Font &font, const std::string &name) : ABasicComponent(pos, font, name) {}

void nts::CXor::simulateComponent() {
    auto input1 = this->_pins[0].getValue();
    auto input2 = this->_pins[1].getValue();

    this->_pins[2].setValue(input1 ^ input2);
}
