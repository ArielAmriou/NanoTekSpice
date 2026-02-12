/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CFalse
*/

#include "CFalse.hpp"

nts::CFalse::CFalse() : AComponent("false") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::CFalse::computeComponent(std::size_t pin) noexcept {
    return nts::False;
}

const std::vector<nts::Pin> nts::CFalse::_defaultPins = {
    nts::Mode::OutputMode,
};
