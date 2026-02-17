/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** COutput
*/

#include "COutput.hpp"

nts::COutput::COutput() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::COutput::simulateComponent() {};

const std::vector<nts::Pin> nts::COutput::_defaultPins = {
    nts::Mode::InputMode
};
