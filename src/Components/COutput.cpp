/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** COutput
*/

#include "COutput.hpp"

nts::COutput::COutput() : AComponent("output") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::COutput::simulate(std::size_t tick) noexcept {
    auto iter = this->_pins.begin();
    auto end = this->_pins.end();
    while (iter != end) {
        if (iter.base()->getMode() == nts::Mode::InputMode) {
            iter.base()->get
        }
        ++iter;
    }
    this->_pins[0].setValue(this->_pins[0].);
}

nts::Tristate nts::COutput::computeComponent(std::size_t pin) noexcept {
    return this->_pins[pin].getValue();
}

const std::vector<nts::Pin> nts::COutput::_defaultPins = {
    nts::Mode::InputMode,
};
