/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nand
*/

#include "C4Nand.hpp"

nts::C4Nand::C4Nand() : AComponent("4011") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C4Nand::simulateComponent() {
    this->_pins[2].setValue(
        !(this->_pins[0].getValue() & this->_pins[1].getValue()));
    this->_pins[3].setValue(
        !(this->_pins[4].getValue() & this->_pins[5].getValue()));
    this->_pins[9].setValue(
        !(this->_pins[7].getValue() & this->_pins[8].getValue()));
    this->_pins[10].setValue(
        !(this->_pins[11].getValue() & this->_pins[12].getValue()));
}

const std::vector<nts::Pin> nts::C4Nand::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};
