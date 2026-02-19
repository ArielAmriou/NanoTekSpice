/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CJohnson
*/

#include "CJohnson.hpp"
#include "Utils.hpp"

nts::CJohnson::CJohnson() : AComponent()
{
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CJohnson::searchTrue()
{
    int i = 0;
    int ret = -1;
    for (auto s = _outputOrder.begin(); s != _outputOrder.end(); ++s) {
        if (this->_pins[*s].getValue() == nts::True) {
            ret = i;
            break;
        }
        ++i;
    }
    if (ret != -1) {
        if (ret <= (_outputOrder.size() / 2) - 1)
            this->_pins[CO].setValue(nts::Tristate::True);
        else
            this->_pins[CO].setValue(nts::Tristate::False);
    }
}

void nts::CJohnson::incrementValues()
{
    auto begin = _outputOrder.begin();
    auto end = _outputOrder.end();
    auto next = begin;
    for (auto s = begin; s != end; ++s) {
        ++next;
        if (this->_pins[*s].getValue() == nts::True) {
            if (next == end) {
                this->_pins[*begin].setValue(nts::True);
            } else {
                this->_pins[*next].setValue(nts::True);
            }
            this->_pins[*s].setValue(nts::False);
            break;
        }
    }
}

void nts::CJohnson::simulateComponent()
{
    nts::Tristate mr = this->_pins[MR].getValue();
    nts::Tristate ctr = this->_pins[CP].getValue();
    nts::Tristate c = this->_pins[CLK].getValue();
    nts::Tristate v = c & !this->_prevC;
    if (mr != nts::Tristate::False || ctr != nts::Tristate::True
        || v == nts::Tristate::Undefined) {
        if (ctr == nts::Tristate::Undefined || v == nts::Tristate::Undefined)
            this->resetOutputs();
        if (mr != nts::Tristate::False)
            this->resetOutputs(!mr);
        if (mr == nts::Tristate::True)
            this->_pins[Q0].setValue(nts::Tristate::True);
        this->searchTrue();
        this->_prevC = c;
        return;
    }
    this->incrementValues();
    this->searchTrue();
    this->_prevC = c;
}

const std::vector<nts::Pin> nts::CJohnson::_defaultPins = {
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};

const std::list<std::size_t> nts::CJohnson::_outputOrder = {
    nts::CJohnson::pins::Q0,
    nts::CJohnson::pins::Q1,
    nts::CJohnson::pins::Q2,
    nts::CJohnson::pins::Q3,
    nts::CJohnson::pins::Q4,
    nts::CJohnson::pins::Q5,
    nts::CJohnson::pins::Q6,
    nts::CJohnson::pins::Q7,
    nts::CJohnson::pins::Q8,
    nts::CJohnson::pins::Q9,
};
