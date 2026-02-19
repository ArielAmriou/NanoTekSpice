/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CAdder
*/

#include "CAdder.hpp"
#include "Utils.hpp"

nts::CAdder::CAdder() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CAdder::simulateComponent() {
    for (auto s = this->_mustValues.begin(); s != this->_mustValues.end(); ++s)
        if (this->_pins[*s].getValue() == nts::Tristate::Undefined) {
            this->resetOutputs();
            return;
        }
    nts::Tristate co = this->_pins[CI].getValue();
    this->_pins[S1].setValue(nts::Utils::fullAdder(this->_pins[B1].getValue(),
        this->_pins[A1].getValue(), co));
    this->_pins[S2].setValue(nts::Utils::fullAdder(this->_pins[B2].getValue(),
        this->_pins[A2].getValue(), co));
    this->_pins[S3].setValue(nts::Utils::fullAdder(this->_pins[B3].getValue(),
        this->_pins[A3].getValue(), co));
    this->_pins[S4].setValue(nts::Utils::fullAdder(this->_pins[B4].getValue(),
        this->_pins[A4].getValue(), co));
    this->_pins[CO].setValue(co);
}

const std::vector<nts::Pin> nts::CAdder::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode
};

const std::list<std::size_t> nts::CAdder::_mustValues = {
    A1,
    A2,
    A3,
    A4,
    B1,
    B2,
    B3,
    B4,
};
