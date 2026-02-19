/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CRam
*/

#include <fstream>
#include <cmath>
#include "CRam.hpp"
#include "NtsException.hpp"

nts::CRam::CRam() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
    for (auto &cell : _mem)
        cell.fill(nts::Undefined);
}

bool nts::CRam::validAdr(int adr)
{
    Tristate ce = _pins[CE].getValue();
    Tristate we = _pins[WE].getValue();
    Tristate oe = _pins[OE].getValue();
    bool done = false;

    if (!ce & !we == True && oe != Undefined) {
        for (std::size_t i = 0; i < BIT; i++)
            _mem[adr][i] = _pins[_duals[i]].getValue();
        done = true;
    } else if (!ce & !oe & we == True) {
        for (std::size_t i = 0; i < BIT; i++)
            _pins[_duals[i]].setValue(_mem[adr][i]);
        done = true;
    }
    return done;
}

void nts::CRam::simulateComponent()
{
    int adr = 0;
    bool undefined = false;
    for (std::size_t i = 0; i < _address.size(); i++) {
        Tristate state = _pins[_address[i]].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        adr += state * static_cast<int>(std::pow(2, i));
    }
    bool change = false;
    if (!undefined)
        change = validAdr(adr);
    if (!change)
        for (std::size_t i = 0; i < BIT; i++)
            _pins[_duals[i]].setValue(Undefined);
}

const std::vector<nts::Pin> nts::CRam::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::DualMode,
    nts::Mode::DualMode,
    nts::Mode::DualMode,
    nts::Mode::UnusedMode,
    nts::Mode::DualMode,
    nts::Mode::DualMode,
    nts::Mode::DualMode,
    nts::Mode::DualMode,
    nts::Mode::DualMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};

const std::vector<nts::CRam::PinName> nts::CRam::_duals = {
    DQ0,
    DQ1,
    DQ2,
    DQ3,
    DQ4,
    DQ5,
    DQ6,
    DQ7,
};

const std::vector<nts::CRam::PinName> nts::CRam::_address = {
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
};