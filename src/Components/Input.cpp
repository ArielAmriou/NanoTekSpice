/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input() : AComponent("input") {
    this->_pins = this->_default_pins;
    this->_nbPins = this->_pins.size();
}

nts::Tristate nts::Input::compute(std::size_t pin) noexcept {
    return nts::Undefined;
}

const std::vector<std::pair<std::optional<std::string>, nts::Mode>> nts::Input::_default_pins = {
    {std::optional<std::string>(), nts::OutputMode}
};
