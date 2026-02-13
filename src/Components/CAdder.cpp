/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CAdder
*/

#include "CAdder.hpp"
#include "BasicOperation.hpp"

nts::CAdder::CAdder() : AComponent("4008") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CAdder::simulateComponent() {
    
}

const std::vector<nts::Pin> nts::CAdder::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
};
