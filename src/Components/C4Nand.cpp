/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nand
*/

#include "C4Nand.hpp"
#include "BasicOperation.hpp"

nts::C4Nand::C4Nand() : AComponent("4011") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C4Nand::simulateComponent(void) {
    for(std::size_t i = 0; i < this->_nbPins; i += 3)
        this->_pins[i + 2].setValue(
            nts::BasicOperation::nandOperation(
            this->_pins[i].getValue(), this->_pins[i + 1].getValue()));
}

const std::vector<nts::Pin> nts::C4Nand::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
};
