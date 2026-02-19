/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CRom
*/

#include <fstream>
#include <cmath>
#include "CRom.hpp"
#include "NtsException.hpp"

nts::CRom::CRom() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
    for (auto &cell : _mem)
        cell.fill(nts::Undefined);
    std::ifstream file("rom.bin", std::ios::binary);
    if (!file.is_open())
        throw OpenFailureException();
    for (std::size_t i = 0; i < ROMMEM; i++) {
        int byte = file.get();
        if (byte == EOF)
            break;
        for (std::size_t j = 0; j < BIT; j++) {
            if ((static_cast<const char>(byte) >> j) & True == True)
                _mem[i][j] = True;
            else
                _mem[i][j] = False;
        }
    }
}

void nts::CRom::simulateComponent()
{
    int bit = 0;
    bool undefined = false;
    for (std::size_t i = 0; i < _address.size(); i++) {
        Tristate state = _pins[_address[i]].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        bit += state * static_cast<int>(std::pow(2, i));
    }
    Tristate signal = _pins[CE].getValue() & !_lastClk;
    _lastClk = _pins[CE].getValue();
    if (signal & _pins[OE].getValue() == True && !undefined) {
        for (std::size_t i = 0; i < BIT; i++) {
            _pins[_outputs[i]].setValue(_mem[bit][i]);
        }
    }
    else if (!_pins[CE].getValue() & !_pins[OE].getValue() == True)
        return;
    else
        for (std::size_t i = 0; i < BIT; i++) {
            _pins[_outputs[i]].setValue(Undefined);
        }
}

const std::vector<nts::Pin> nts::CRom::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::UnusedMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};

const std::vector<nts::CRom::PinName> nts::CRom::_outputs = {
    Q0,
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6,
    Q7,
};

const std::vector<nts::CRom::PinName> nts::CRom::_address = {
    A0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,
    A8,
    A9,
    A10,
};