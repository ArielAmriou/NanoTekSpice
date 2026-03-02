/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CJohnson
*/

#include "CJohnson.hpp"
#include "Utils.hpp"

nts::CJohnson::CJohnson(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CJOHNSONX, CJOHNSONY}, font, _defaultPins)
{
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
    if (mr != nts::Tristate::False || ctr != nts::Tristate::False
        || v != nts::Tristate::True) {
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

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CJohnson::_defaultPins = {
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 6}, "Q5", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 2}, "Q1", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12}, "Q0", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 3}, "Q2", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 7}, "Q6", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 8}, "Q7", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 4}, "Q3", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VSS", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 9}, "Q8", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 5}, "Q4", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 10}, "Q9", nts::Undefined},
    {nts::Mode::OutputMode, {CJOHNSONX - SIDEOFFSET, CJOHNSONY / 12 * 11}, "C0", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CJOHNSONY / 4 * 1}, "CP", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CJOHNSONY / 4 * 2}, "CLK", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CJOHNSONY / 4 * 3}, "MR", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VDD", nts::Undefined},
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
