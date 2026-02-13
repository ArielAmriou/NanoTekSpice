/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Or
*/

#include "C4Or.hpp"

nts::C4Or::C4Or() : AComponent("4071") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C4Or::simulateComponent() {
    this->_pins[2].setValue(
        this->_pins[0].getValue() | this->_pins[1].getValue());
    this->_pins[3].setValue(
        this->_pins[4].getValue() | this->_pins[5].getValue());
    this->_pins[8].setValue(
        this->_pins[6].getValue() | this->_pins[7].getValue());
    this->_pins[9].setValue(
        this->_pins[10].getValue() | this->_pins[11].getValue());
}

const std::vector<nts::Pin> nts::C4Or::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
};
