/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output() : AComponent("output") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::Output::compute(std::size_t pin) noexcept {
    return nts::Undefined;
}

const std::vector<nts::Pin> nts::Output::_defaultPins = {
    nts::Mode::InputMode,
};
