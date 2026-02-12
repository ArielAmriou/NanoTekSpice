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

void nts::CTrue::simulateComponent(void) {};

const std::vector<nts::Pin> nts::CTrue::_defaultPins = {
    {nts::Mode::OutputMode, nts::True},
};
