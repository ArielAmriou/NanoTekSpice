/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CSelector
*/

#include <cmath>
#include "CSelector.hpp"

nts::CSelector::CSelector() : AComponent("4512") {
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CSelector::simulateComponent() {
    int bit = 0;
    bool undefined = false;
    for (std::size_t i = 0; i < C - A + 1; i++) {
        Tristate state = _pins[i + A].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        bit += state * static_cast<int>(std::pow(2, i));
    }
    if (bit == VSS)
        bit += 1;
    if (undefined || _pins[OE].getValue() != 0
        || _pins[INHIBIT].getValue() == Undefined)
        _pins[Z].setValue(Undefined);
    else if (_pins[INHIBIT].getValue() == 1)
        _pins[Z].setValue(False);
    else
        _pins[Z].setValue(_pins[bit].getValue());
}

const std::vector<nts::Pin> nts::CSelector::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};