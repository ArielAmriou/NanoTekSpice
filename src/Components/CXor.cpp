/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CXor
*/

#include "CXor.hpp"
#include "BasicOperation.hpp"

nts::CXor::CXor() : AComponent("and") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CXor::simulateComponent(void) {
    auto input1 = this->_pins[0].getValue();
    auto input2 = this->_pins[1].getValue();

    this->_pins[2].setValue(
        nts::BasicOperation::xorOperation(input1, input2));
}

const std::vector<nts::Pin> nts::CXor::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
