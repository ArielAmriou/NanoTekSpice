/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CDualFlipFlop
*/

#include "CDualFlipFlop.hpp"

nts::CDualFlipFlop::CDualFlipFlop() : AComponent()
{
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

bool nts::CDualFlipFlop::handleAsync(PinName q, PinName nq,
    PinName set, PinName reset)
{
    Tristate s = _pins[set].getValue();
    Tristate r = _pins[reset].getValue();
    bool value = true;

    if (s != True && r != True)
        value = false;
    _pins[q].setValue(s);
    _pins[nq].setValue(r);
    return value;
}

void nts::CDualFlipFlop::simulateFlipFlop(PinName q, PinName nq,
    PinName clk, PinName data, Tristate &lastClk)
{
    Tristate c    = _pins[clk].getValue();
    Tristate rise = c & !lastClk;
    lastClk = c;

    if (rise == True) {
        Tristate d = _pins[data].getValue();
        _pins[q].setValue(d);
        _pins[nq].setValue(!d);
    }
}

void nts::CDualFlipFlop::simulateComponent()
{
    if (!handleAsync(Q1, Q_1, S1, R1))
        simulateFlipFlop(Q1, Q_1, CLK1, D1, _lastClk1);
    if (!handleAsync(Q2, Q_2, S2, R2))
        simulateFlipFlop(Q2, Q_2, CLK2, D2, _lastClk2);
}

const std::vector<nts::Pin> nts::CDualFlipFlop::_defaultPins = {
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
};
