/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nor
*/

#include "C4Nor.hpp"
#include "BasicOperation.hpp"

nts::C4Nor::C4Nor() : AComponent("4001") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C4Nor::simulateComponent(void) {
    for(std::size_t i = 0; i < this->_nbPins; i += 3)
        this->_pins[i + 2].setValue(
            nts::BasicOperation::norOperation(
            this->_pins[i].getValue(), this->_pins[i + 1].getValue()));
}

const std::vector<nts::Pin> nts::C4Nor::_defaultPins = {
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
