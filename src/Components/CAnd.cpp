/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CAnd
*/

#include "CAnd.hpp"
#include "BasicOperation.hpp"

nts::CAnd::CAnd() : AComponent("and") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CAnd::simulateComponent(void) {
    auto input1 = this->_pins[0].getValue();
    auto input2 = this->_pins[1].getValue();
    
    this->_pins[2].setValue(
        nts::BasicOperation::andOperation(input1, input2));
}

const std::vector<nts::Pin> nts::CAnd::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
