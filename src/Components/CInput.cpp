/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CInput
*/

#include "CInput.hpp"

nts::CInput::CInput() : AComponent("input") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::CInput::computeComponent(std::size_t pin) noexcept {
    return this->_pins[pin].getValue();
}

const std::vector<nts::Pin> nts::CInput::_defaultPins = {
    nts::Mode::OutputMode,
};
