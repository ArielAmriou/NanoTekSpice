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

nts::Tristate nts::CDualFlipFlop::simulateCLock(
    Tristate d, Tristate clk, Tristate lastClk, Tristate q)
{
    Tristate signal = clk & !lastClk;
    return (d & signal) | (q & signal);
}

nts::Tristate nts::CDualFlipFlop::simulateFilpFlop(
    Tristate clkSignal, Tristate r, Tristate s)
{
    Tristate set = s & !r;
    Tristate reset = r & !s;
    Tristate both = r & s;
    Tristate none = !r & !s;
    Tristate setOrReset = set | (False & reset);
    Tristate bothOrNone = (both & Undefined) | (clkSignal & none);
    return setOrReset | bothOrNone;
}

void nts::CDualFlipFlop::simulateComponent()
{
    Tristate sClk1 = simulateCLock(
        _pins[PinName::D1].getValue(), _pins[PinName::CLK1].getValue(),
        _lastClk1, _pins[PinName::Q1].getValue());
    Tristate result1 = simulateFilpFlop(sClk1,
        _pins[PinName::R1].getValue(), _pins[PinName::S1].getValue());
    _pins[PinName::Q1].setValue(result1);
    _pins[PinName::Q_1].setValue(!result1);
    _lastClk1 = _pins[PinName::CLK1].getValue();

    Tristate sClk2 = simulateCLock(
        _pins[PinName::D2].getValue(), _pins[PinName::CLK2].getValue(),
        _lastClk2, _pins[PinName::Q2].getValue());
    Tristate result2 = simulateFilpFlop(sClk2,
        _pins[PinName::R2].getValue(), _pins[PinName::S2].getValue());
    _pins[PinName::Q2].setValue(result2);
    _pins[PinName::Q_2].setValue(!result2);
    _lastClk2 = _pins[PinName::CLK2].getValue();
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
    nts::Mode::UnusedMode
};
