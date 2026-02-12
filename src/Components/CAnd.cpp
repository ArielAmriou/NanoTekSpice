/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CAnd
*/

#include "CAnd.hpp"

nts::CAnd::CAnd() : AComponent("and") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CAnd::simulateComponent(void) {
    auto input1 = this->_pins[0].getValue();
    auto input2 = this->_pins[1].getValue();
    if (input1 == input2)
        this->_pins[2].setValue(input1);
    else if (input1 == nts::False || input2 == nts::False)
        this->_pins[2].setValue(nts::False);
    else if (input1 == nts::Undefined || input2 == nts::Undefined)
        this->_pins[2].setValue(nts::Undefined);
    else
        this->_pins[2].setValue(nts::True);
}

const std::vector<nts::Pin> nts::CAnd::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
