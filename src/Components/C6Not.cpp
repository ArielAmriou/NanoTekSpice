/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C6Not
*/

#include "C6Not.hpp"

nts::C6Not::C6Not()
    : APartComponent(C6NOTNBPART, C6NOTNBIN,
        C6NOTNBOUT)
{
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::C6Not::computePart(std::size_t id)
{
    this->_pins[_outputs[id]].setValue(
        !this->_pins[_inputs[id]].getValue());
}

const std::vector<nts::Pin> nts::C6Not::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};

const std::vector<std::size_t> nts::C6Not::_inputs = {
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
};

const std::vector<std::size_t> nts::C6Not::_outputs = {
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6
};