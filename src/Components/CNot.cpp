/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CNot
*/

#include "CNot.hpp"

nts::CNot::CNot() : AComponent("not") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::CNot::computeComponent(std::size_t pin) noexcept {
    return nts::True;
}

const std::vector<nts::Pin> nts::CNot::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
};
