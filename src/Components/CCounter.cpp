/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CCounter
*/

#include "CCounter.hpp"
#include "Utils.hpp"

nts::CCounter::CCounter() : AComponent()
{
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CCounter::incrementValues()
{
    nts::Tristate carry = this->_pins[C].getValue();
    for (auto s = _outputOrder.begin(); s != _outputOrder.end(); ++s) {
        nts::Pin &pin = this->_pins[*s];
        nts::Tristate value = pin.getValue();
        nts::Tristate one;
        if (value == nts::Tristate::Undefined)
            value = nts::Tristate::False;
        if (s == _outputOrder.begin()) {
            one = nts::Tristate::True;
        }
        else
            one = nts::Tristate::False;
        auto tmp = nts::Utils::halfAdder(one ^ carry, value, carry);
        pin.setValue(tmp);
    }
}

void nts::CCounter::simulateComponent()
{
    nts::Tristate c = this->_pins[C].getValue();
    nts::Tristate r = this->_pins[R].getValue();
    if (r != nts::Tristate::False) {
        this->_prevC = c;
        return this->resetOutputs(!r);
    }
    nts::Tristate v = this->_pins[C].getValue() & !this->_prevC;
    if (v == nts::Tristate::Undefined) {
        this->_prevC = c;
        return this->resetOutputs();
    }
    this->incrementValues();
    this->_prevC = c;
}

const std::vector<nts::Pin> nts::CCounter::_defaultPins = {
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
};

const std::list<std::size_t> nts::CCounter::_outputOrder = {
    nts::CCounter::pins::Q1,
    nts::CCounter::pins::Q2,
    nts::CCounter::pins::Q3,
    nts::CCounter::pins::Q4,
    nts::CCounter::pins::Q5,
    nts::CCounter::pins::Q6,
    nts::CCounter::pins::Q7,
    nts::CCounter::pins::Q8,
    nts::CCounter::pins::Q9,
    nts::CCounter::pins::Q10,
    nts::CCounter::pins::Q11,
    nts::CCounter::pins::Q12,
};
