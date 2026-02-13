/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C6Not
*/

#include "C6Not.hpp"
#include "BasicOperation.hpp"

nts::C6Not::C6Not() : AComponent("4069") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C6Not::simulateComponent() {
    for(std::size_t i = 0; i < this->_nbPins / 2; i += 2)
        this->_pins[i + 1].setValue(
            nts::BasicOperation::notOperation(this->_pins[i].getValue()));
    for(std::size_t i = this->_nbPins / 2; i < this->_nbPins; i += 2)
        this->_pins[i].setValue(
            nts::BasicOperation::notOperation(this->_pins[i + 1].getValue()));
}

const std::vector<nts::Pin> nts::C6Not::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,

    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
};
