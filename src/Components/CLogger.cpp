/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CLogger
*/

#include <cmath>
#include <fstream>
#include "CLogger.hpp"

nts::CLogger::CLogger() : AComponent()
{
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

void nts::CLogger::writeInFile(char value)
{
    std::ofstream file("./log.bin", std::ios::app | std::ios::binary);
    
    if (file.is_open()) {
        file.put(value);
        file.close();
    }
}

void nts::CLogger::simulateComponent()
{
    unsigned char value = 0;
    bool undefined = false;

    for (std::size_t i = 0; i < LOGGERBITS; i++) {
        Tristate state = _pins[i].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        value += state * static_cast<int>(std::pow(2, i)) % MAXCHARSIZE;
    }
    Tristate append = !_pins[9].getValue() & (_pins[8].getValue() & !_lastClk);
    _lastClk = _pins[8].getValue();
    if (undefined || append != True)
        return;
    writeInFile(value);
}

const std::vector<nts::Pin> nts::CLogger::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
};

