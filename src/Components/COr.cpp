/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** COr
*/

#include "COr.hpp"
#include "BasicOperation.hpp"

nts::COr::COr() : AComponent("and") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::COr::simulateComponent() {
    auto input1 = this->_pins[0].getValue();
    auto input2 = this->_pins[1].getValue();

    this->_pins[2].setValue(
        nts::BasicOperation::orOperation(input1, input2));
}

const std::vector<nts::Pin> nts::COr::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
