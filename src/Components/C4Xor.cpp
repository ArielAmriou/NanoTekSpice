/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Xor
*/

#include "C4Xor.hpp"
#include "BasicOperation.hpp"

nts::C4Xor::C4Xor() : AComponent("4030") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C4Xor::simulateComponent(void) {
    this->_pins[2].setValue(nts::BasicOperation::xorOperation(
        this->_pins[0].getValue(), this->_pins[1].getValue()));
    this->_pins[3].setValue(nts::BasicOperation::xorOperation(
        this->_pins[4].getValue(), this->_pins[5].getValue()));
    this->_pins[8].setValue(nts::BasicOperation::xorOperation(
        this->_pins[6].getValue(), this->_pins[7].getValue()));
    this->_pins[9].setValue(nts::BasicOperation::xorOperation(
        this->_pins[10].getValue(), this->_pins[11].getValue()));
}

const std::vector<nts::Pin> nts::C4Xor::_defaultPins = {
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
