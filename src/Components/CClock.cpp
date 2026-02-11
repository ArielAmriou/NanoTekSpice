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

nts::Tristate nts::CClock::compute(std::size_t pin) noexcept {
    return nts::Undefined;
}

const std::vector<nts::Pin> nts::CClock::_defaultPins = {
    nts::Mode::OutputMode,
};
