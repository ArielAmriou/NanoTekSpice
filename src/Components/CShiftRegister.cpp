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
    Tristate data = _pins[DATA].getValue();
    bool done = false;

    if (enable & strobe & !data == True) {
        _pins[QS].setValue(_pins[Q7].getValue());
        for (std::size_t i = _outputs.size() - 1; i > 0; i--)
            _pins[_outputs[i]].setValue(_pins[_outputs[i - 1]].getValue());
        _pins[Q0].setValue(False);
        done = true;
    } else if (enable & strobe & data == True) {
        _pins[QS].setValue(_pins[Q7].getValue());
        for (std::size_t i = _outputs.size() - 1; i > 0; i--)
            _pins[_outputs[i]].setValue(_pins[_outputs[i - 1]].getValue());
        _pins[Q0].setValue(True);
        done = true;
    }
    return done;
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
    } else if (!strobe & enable == true) {
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
    Tristate data = _pins[DATA].getValue();
    bool done = false;

    if (enable == False) {
        _pins[QSS].setValue(_pins[Q7].getValue());
        for (std::size_t i = 0; i < _outputs.size(); i++)
            _pins[_outputs[i]].setValue(Undefined);
        done = true;
    } else if (enable & strobe & data == True) {
        _pins[QSS].setValue(_pins[Q7].getValue());
        done = true;
    }
    if (done == false && strobe & data != Undefined)
        done = true;
    return done;
}

void nts::CShiftRegister::simulateComponent()
{
    Tristate raseSignal = _pins[CLK].getValue() & !_lastClk;
    Tristate lowerSignal = !_pins[CLK].getValue() & _lastClk;
    _lastClk = _pins[CLK].getValue();
    bool change = false;

    if (raseSignal == True) {
        change = handleRaseSignal();
    } else if (lowerSignal == True) {
        change = handleLowerSignal();
    }
    if (change || !raseSignal & !lowerSignal == True)
        return;
    else {
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
    Q0,
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6,
    Q7,
};