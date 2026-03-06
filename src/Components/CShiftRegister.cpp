/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CShiftRegister
*/

#include <fstream>
#include <cmath>
#include "CShiftRegister.hpp"
#include "NtsException.hpp"

nts::CShiftRegister::CShiftRegister() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

bool nts::CShiftRegister::handleData()
{
    Tristate enable = _pins[ENABLE].getValue();
    Tristate strobe = _pins[STROBE].getValue();
    Tristate data   = _pins[DATA].getValue();

    if ((enable & strobe) != True)
        return false;
    _pins[QS].setValue(_pins[Q7].getValue());
    for (std::size_t i = _outputs.size() - 1; i > 0; i--)
        _pins[_outputs[i]].setValue(_pins[_outputs[i - 1]].getValue());
    _pins[Q1].setValue(data);
    return true;
}

bool nts::CShiftRegister::handleRaseSignal()
{
    Tristate enable = _pins[ENABLE].getValue();
    Tristate strobe = _pins[STROBE].getValue();
    bool done = false;

    if (enable == False) {
        _pins[QS].setValue(_pins[Q7].getValue());
        for (std::size_t i = 0; i < _outputs.size(); i++)
            _pins[_outputs[i]].setValue(Undefined);
        done = true;
    } else if ((!strobe & enable) == True) {
        _pins[QS].setValue(_pins[Q7].getValue());
        done = true;
    } else {
        done = handleData();
    }
    return done;
}

bool nts::CShiftRegister::handleLowerSignal()
{
    Tristate enable = _pins[ENABLE].getValue();
    Tristate strobe = _pins[STROBE].getValue();

    if (enable == False) {
        for (std::size_t i = 0; i < _outputs.size(); i++)
            _pins[_outputs[i]].setValue(Undefined);
        _pins[QSS].setValue(_pins[Q7].getValue());
        return true;
    }
    if ((enable & strobe) == True) {
        _pins[QSS].setValue(_pins[Q7].getValue());
        return true;
    }
    return false;
}

void nts::CShiftRegister::simulateComponent()
{
    Tristate clk = _pins[CLK].getValue();
    Tristate riseSignal  = clk & !_lastClk;
    Tristate lowerSignal = !clk & _lastClk;
    _lastClk = clk;
    bool change = false;

    if (riseSignal == True)
        change = handleRaseSignal();
    else if (lowerSignal == True)
        change = handleLowerSignal();
    if (!change && (!riseSignal & !lowerSignal) == True) {
        for (std::size_t i = 0; i < _outputs.size(); i++)
            _pins[_outputs[i]].setValue(Undefined);
        _pins[QS].setValue(Undefined);
        _pins[QSS].setValue(Undefined);
    }
}
const std::vector<nts::Pin> nts::CShiftRegister::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,

};

const std::vector<nts::CShiftRegister::PinName>
    nts::CShiftRegister::_outputs = {
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6,
    Q7,
    Q8,
};