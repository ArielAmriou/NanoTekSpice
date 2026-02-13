/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CAdder
*/

#include "CAdder.hpp"

nts::CAdder::CAdder() : AComponent("4008") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

static nts::Tristate halfAdder(const nts::Tristate a,
    const nts::Tristate b, nts::Tristate &carry) {
    carry = a & b;
    return a ^ b;
}

void nts::CAdder::simulateComponent() {
    for (auto s = this->_mustValues.begin(); s != this->_mustValues.end(); ++s)
        if (this->_pins[*s].getValue() == nts::Tristate::Undefined) {
            this->_pins[S1].setValue(nts::Tristate::Undefined);
            this->_pins[S2].setValue(nts::Tristate::Undefined);
            this->_pins[S3].setValue(nts::Tristate::Undefined);
            this->_pins[S4].setValue(nts::Tristate::Undefined);
            this->_pins[CO].setValue(nts::Tristate::Undefined);
            return;
        }
    nts::Tristate co = this->_pins[CI].getValue();
    this->_pins[S4].setValue(halfAdder(this->_pins[B4].getValue(),
        this->_pins[A4].getValue() ^ co, co));
    this->_pins[S3].setValue(halfAdder(this->_pins[B3].getValue(),
        this->_pins[A3].getValue() ^ co, co));
    this->_pins[S2].setValue(halfAdder(this->_pins[B2].getValue(),
        this->_pins[A2].getValue() ^ co, co));
    this->_pins[S1].setValue(halfAdder(this->_pins[B1].getValue(),
        this->_pins[A1].getValue() ^ co, co));
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

const std::list<int> nts::CAdder::_mustValues = {
    A1,
    A2,
    A3,
    A4,
    B1,
    B2,
    B3,
    B4,
};
