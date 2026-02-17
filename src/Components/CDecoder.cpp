/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CDecoder
*/

#include <cmath>
#include "CDecoder.hpp"

nts::CDecoder::CDecoder() : AComponent() {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CDecoder::simulateComponent() {
    int bit = 0;
    bool undefined = false;
    for (std::size_t i = 0; i < _inputs.size(); i++) {
        Tristate state = _pins[_inputs[i]].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        bit += state * static_cast<int>(std::pow(2, i));
    }
    for (auto pin : _outputs) {
        _pins[pin].setValue(False);
    }
    if (_pins[INHIBIT].getValue() == True || _pins[STROBE].getValue() == True)
        return;
    else if (undefined
        || _pins[INHIBIT].getValue() & _pins[STROBE].getValue() == Undefined)
        for (auto pin : _outputs) {
            _pins[pin].setValue(Undefined);
        }
    else
        _pins[_outputs[bit]].setValue(True);
}

const std::vector<nts::Pin> nts::CDecoder::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
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
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};

const std::vector<nts::CDecoder::PinName> nts::CDecoder::_outputs = {
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    S8,
    S9,
    S10,
    S11,
    S12,
    S13,
    S14,
    S15,
};

const std::vector<nts::CDecoder::PinName> nts::CDecoder::_inputs = {
    A,
    B,
    C,
    D
};