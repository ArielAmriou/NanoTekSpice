/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CCounter
*/

#include "CCounter.hpp"
#include "Utils.hpp"

nts::CCounter::CCounter(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CCOUNTERX, CCOUNTERY}, font, _defaultPins)
{
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
    nts::Tristate v = c & !this->_prevC;
    if (v == nts::Tristate::Undefined) {
        this->_prevC = c;
        return this->resetOutputs();
    }
    this->incrementValues();
    this->_prevC = c;
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CCounter::_defaultPins = {
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 12}, "Q12", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 6}, "Q6", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 5}, "Q5", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 7}, "Q7", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 4}, "Q4", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 3}, "Q3", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 2}, "Q2", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VSS", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13}, "Q1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CCOUNTERY / 3}, "CLK", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CCOUNTERY / 3 * 2}, "RESET", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 9}, "Q9", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 8}, "Q8", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 10}, "Q10", nts::Undefined},
    {nts::Mode::OutputMode, {CCOUNTERX - SIDEOFFSET, CCOUNTERY / 13 * 11}, "Q11", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VDD", nts::Undefined},
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
