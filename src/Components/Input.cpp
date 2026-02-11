/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input() : AComponent("input") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::Input::compute(std::size_t pin) noexcept {
    return nts::Undefined;
}

const std::vector<nts::Pin> nts::Input::_defaultPins = {
    nts::Mode::OutputMode,
};
