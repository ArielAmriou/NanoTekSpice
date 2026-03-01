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

nts::CRom::CRom(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CROMX, CROMY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();

    _textOffset = {-CROMTEXTOFFSET, 0};
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
    _text.setFont(font);
    _text.setCharacterSize(10);
    _text.setString("o");
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
        _bit = bit;
        for (std::size_t i = 0; i < BIT; i++) {
            _pins[_outputs[i]].setValue(_mem[bit][i]);
        }
    }
    else if (!_pins[CE].getValue() & !_pins[OE].getValue() == True)
        return;
    else {
        for (std::size_t i = 0; i < BIT; i++) {
            _pins[_outputs[i]].setValue(Undefined);
        }
        _bit = -1;
    }
}

char nts::CRom::getChar(std::array<Tristate, BIT> byte)
{
    char c = 0;

    for (std::size_t i = 0; i < BIT; i++) {
        if (byte[i] == Undefined)
            return 0;
        c += byte[i] * static_cast<int>(std::pow(2, i));
    }
    return c;
}

void nts::CRom::drawComponent(sf::RenderWindow &window)
{
    float x = 50;
    float y = CROMGAP;

    for (std::size_t i = 0; i < CROMNBLINE; i++) {
        for (std::size_t j = 0; j < CROMNBCOLUMN; j++) {
            std::string str = "";
            _text.setFillColor(sf::Color::Black);
            if (i * CROMNBCOLUMN + (j + 1) == _bit)
                _text.setFillColor(sf::Color::Red);
            str += getChar(_mem[i * CROMNBCOLUMN + j]);
            _text.setString(str);
            _text.setPosition(_pos.x + x, _pos.y + y);
            window.draw(_text);
            x += CROMGAP;
        }
        y += CROMGAP;
        x = 50;
    }
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CRom::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 8}, "A7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 7}, "A6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 6}, "A5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 5}, "A4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 4}, "A3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 3}, "A2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 2}, "A1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14}, "A0", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9}, "Q0", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 2}, "Q1", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 3}, "Q2", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VSS", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 4}, "Q3", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 5}, "Q4", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 6}, "Q5", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 7}, "Q6", nts::Undefined},
    {nts::Mode::OutputMode, {CROMX - SIDEOFFSET, CROMY / 9 * 8}, "Q7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 12}, "CE", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 11}, "A10", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 13}, "OE", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VPP", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 10}, "A9", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CROMY / 14 * 9}, "A8", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VCC", nts::Undefined},
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