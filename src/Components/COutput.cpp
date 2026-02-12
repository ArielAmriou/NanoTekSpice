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

nts::Tristate nts::COutput::computeComponent(std::size_t pin) noexcept {
    return nts::Undefined;
}

const std::vector<nts::Pin> nts::COutput::_defaultPins = {
    nts::Mode::InputMode,
};
