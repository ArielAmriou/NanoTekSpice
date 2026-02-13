/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CNot
*/

#include "CNot.hpp"

nts::CNot::CNot() : AComponent("not") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CNot::simulateComponent() {
    this->_pins[1].setValue(!(this->_pins[0].getValue()));
}

const std::vector<nts::Pin> nts::CNot::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
