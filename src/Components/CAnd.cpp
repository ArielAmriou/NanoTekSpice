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
    auto value = this->_pins[0].getValue();
    if (value == nts::True)
        this->_pins[1].setValue(nts::False);
    else if (value == nts::False)
        this->_pins[1].setValue(nts::True);
    else
        this->_pins[1].setValue(nts::Undefined);
}

const std::vector<nts::Pin> nts::CAnd::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode
};
