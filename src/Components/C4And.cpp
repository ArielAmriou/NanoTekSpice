/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4And
*/

#include "C4And.hpp"
#include "BasicOperation.hpp"

nts::C4And::C4And() : AComponent("4081") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C4And::simulateComponent(void) {
    for(std::size_t i = 0; i < this->_nbPins; i += 3)
        this->_pins[i + 2].setValue(
            nts::BasicOperation::andOperation(
            this->_pins[i].getValue(), this->_pins[i + 1].getValue()));
}

const std::vector<nts::Pin> nts::C4And::_defaultPins = {
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
