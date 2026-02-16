/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** COr
*/

#include "COr.hpp"

nts::COr::COr() : AComponent("or") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::COr::simulateComponent()
{
    this->_pins[2].setValue(
        this->_pins[0].getValue() | this->_pins[1].getValue());
}

const std::vector<nts::Pin> nts::COr::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
