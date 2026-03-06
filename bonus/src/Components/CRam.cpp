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

nts::CRam::CRam(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CRAMX, CRAMY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
    _textOffset = {-CRAMTEXTOFFSET, 0};
    for (auto &cell : _mem)
        cell.fill(nts::Undefined);
    _text.setFont(font);
    _text.setCharacterSize(10);
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

char nts::CRam::getChar(std::array<Tristate, BIT> byte)
{
    char c = 0;

    for (std::size_t i = 0; i < BIT; i++) {
        if (byte[i] == Undefined)
            return -1;
        c += byte[i] * static_cast<int>(std::pow(2, i));
    }
    return c;
}

void nts::CRam::drawComponent(sf::RenderWindow &window)
{
    float x = 50;
    float y = CRAMGAP;

    for (std::size_t i = 0; i < CRAMNBLINE; i++) {
        for (std::size_t j = 0; j < CRAMNBCOLUMN; j++) {
            std::string str = "";
            _text.setFillColor(sf::Color::Black);
            if (i * CRAMNBCOLUMN + j == _bit)
                _text.setFillColor(sf::Color::Red);
            char c = getChar(_mem[i * CRAMNBCOLUMN + j]);
            if (c < 0) {
                str = "U";
                _text.setFillColor(sf::Color::White);
            } else
                str += c;
            _text.setString(str);
            _text.setPosition(_pos.x + x, _pos.y + y);
            window.draw(_text);
            x += CRAMGAP;
        }
        y += CRAMGAP;
        x = 50;
    }
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CRam::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 8}, "A7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 7}, "A6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 6}, "A5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 5}, "A4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 4}, "A3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 3}, "A2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 2}, "A1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14}, "A0", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9}, "DQ0", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 2}, "DQ1", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 3}, "DQ2", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VSS", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 4}, "DQ3", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 5}, "DQ4", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 6}, "DQ5", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 7}, "DQ6", nts::Undefined},
    {nts::Mode::DualMode, {CRAMX - SIDEOFFSET, CRAMY / 9 * 8}, "DQ7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 12}, "CE", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "NC", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 13}, "OE", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 11}, "WE", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 10}, "A9", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CRAMY / 14 * 9}, "A8", nts::Undefined},
    {nts::Mode::UnusedMode, {0, 0}, "VCC", nts::Undefined},
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