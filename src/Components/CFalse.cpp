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

void nts::CFalse::simulateComponent(void) {};

const std::vector<nts::Pin> nts::CFalse::_defaultPins = {
    {nts::Mode::OutputMode, nts::False}
};
