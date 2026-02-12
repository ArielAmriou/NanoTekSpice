/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CClock
*/

#include "CClock.hpp"

nts::CClock::CClock() : AComponent("clock") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::CClock::computeComponent(std::size_t pin) noexcept {
    nts::Tristate value = this->_pins[pin].getValue();
    if (value == nts::True)
        this->_pins[pin].setValue(nts::False);
    if (value == nts::False)
        this->_pins[pin].setValue(nts::True);
    return value;
}

const std::vector<nts::Pin> nts::CClock::_defaultPins = {
    nts::Mode::OutputMode,
};
