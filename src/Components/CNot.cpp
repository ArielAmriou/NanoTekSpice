/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CNot
*/

#include "CNot.hpp"
#include "BasicOperation.hpp"

nts::CNot::CNot() : AComponent("not") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CNot::simulateComponent(void) {
    this->_pins[1].setValue(
        nts::BasicOperation::notOperation(this->_pins[0].getValue()));
}

const std::vector<nts::Pin> nts::CNot::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
