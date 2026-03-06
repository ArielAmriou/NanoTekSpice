/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CDualFlipFlop
*/

#include "CDualFlipFlop.hpp"

nts::CDualFlipFlop::CDualFlipFlop()
    : APartComponent(CFLIPFLOPNBPART, CFLIPFLOPNBIN,
        CFLIPFLOPNBOUT)
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

    if (!s & !r == True)
        value = false;
    if (s == Undefined || r == Undefined) {
        value = true;
        _pins[q].setValue(Undefined);
        _pins[nq].setValue(Undefined);
    } else if (value) {
        _pins[q].setValue(s);
        _pins[nq].setValue(r);
    }
    return value;
}

void nts::CDualFlipFlop::simulateFlipFlop(PinName q, PinName nq,
    PinName clk, PinName data, Tristate &lastClk)
{
    Tristate c    = _pins[clk].getValue();
    Tristate rise = c & !lastClk;
    lastClk = c;

    if (rise == True ) {
        Tristate d = _pins[data].getValue();
        _pins[q].setValue(d);
        _pins[nq].setValue(!d);
    }
}

void nts::CDualFlipFlop::computePart(std::size_t id)
{
    if (id == 0) {
        if (!handleAsync(Q1, Q_1, S1, R1))
            simulateFlipFlop(Q1, Q_1, CLK1, D1, _lastClk1);
    } else {
        if (!handleAsync(Q2, Q_2, S2, R2))
            simulateFlipFlop(Q2, Q_2, CLK2, D2, _lastClk2);
    }
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

const std::vector<std::size_t> nts::CDualFlipFlop::_inputs = {
    CLK1,
    D1,
    S1,
    R1,
    CLK2,
    D2,
    S2,
    R2,
};

const std::vector<std::size_t> nts::CDualFlipFlop::_outputs = {
    Q1,
    Q_1,
    Q2,
    Q_2,
};
