/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CTrue
*/

#include "CTrue.hpp"

nts::CTrue::CTrue() : AComponent("true") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::CTrue::compute(std::size_t pin) noexcept {
    return nts::Undefined;
}

const std::vector<nts::Pin> nts::CTrue::_defaultPins = {
    nts::Mode::OutputMode,
};
