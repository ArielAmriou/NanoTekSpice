/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CClock
*/

#include "CClock.hpp"

nts::CClock::CClock() : AComponent("clock") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CClock::simulateComponent() {
    auto value = this->_pins[0].getValue();
    this->_pins[0].setValue(!value);
}

const std::vector<nts::Pin> nts::CClock::_defaultPins = {
    nts::Mode::OutputMode
};
