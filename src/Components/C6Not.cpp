/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C6Not
*/

#include "C6Not.hpp"

nts::C6Not::C6Not() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C6Not::simulateComponent() {
    this->_pins[1].setValue(!this->_pins[0].getValue());
    this->_pins[3].setValue(!this->_pins[2].getValue());
    this->_pins[5].setValue(!this->_pins[4].getValue());
    this->_pins[7].setValue(!this->_pins[8].getValue());
    this->_pins[9].setValue(!this->_pins[10].getValue());
    this->_pins[11].setValue(!this->_pins[12].getValue());
}

const std::vector<nts::Pin> nts::C6Not::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};
