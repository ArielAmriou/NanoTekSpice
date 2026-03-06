/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CMatrix
*/

#include <fstream>
#include <cmath>
#include "CMatrix.hpp"
#include "NtsException.hpp"

nts::CMatrix::CMatrix(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CMATRIXX, CMATRIXY}, font, _defaultPins), _pix({CMATRIXGAP, CMATRIXGAP})
{
    this->_nbPins = this->_pins.size();
    _textOffset = {-CMATRIXTEXTOFFSET, 0};
    for (auto &cell : _mem)
        cell.fill(nts::Undefined);
}

void nts::CMatrix::simulateComponent()
{
    int adr = 0;
    bool undefined = false;
    for (std::size_t i = 0; i < NBMATRIXADR; i++) {
        Tristate state = _pins[i].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        adr += state * static_cast<int>(std::pow(2, i));
    }
    if (!undefined) {
        _bit = adr;
        for (std::size_t i = NBMATRIXADR; i < NBMATRIXADR + NBMATRIXCOLOR; i++)
            _mem[adr][i - NBMATRIXADR] = _pins[i].getValue();
    }
}

sf::Color nts::CMatrix::getColor(std::array<Tristate, BIT> byte)
{
    unsigned char value = 0;

    for (std::size_t i = 0; i < BIT; i++) {
        if (byte[i] == Undefined)
            return sf::Color::White;
        value += byte[i] * static_cast<int>(std::pow(2, i));
    }
    uint8_t red   = ((value & 0xE0) >> 5) * 32;
    uint8_t green = ((value & 0x1C) >> 2) * 32;
    uint8_t blue  = ((value & 0x03) >> 0) * 64;
    return {red, green, blue};
}

void nts::CMatrix::drawComponent(sf::RenderWindow &window)
{
    float x = 50;
    float y = CMATRIXGAP;

    _pix.setPosition(_pos.x + x, _pos.y + y);
    _pix.setSize({CMATRIXGAP * CMATRIXNBCOLUMN, CMATRIXGAP * CMATRIXNBLINE});
    _pix.setOutlineColor(sf::Color::Black);
    _pix.setOutlineThickness(3);
    window.draw(_pix);
    _pix.setSize({CMATRIXGAP, CMATRIXGAP});
    _pix.setOutlineColor(sf::Color::Transparent);
    for (std::size_t i = 0; i < CMATRIXNBLINE; i++) {
        for (std::size_t j = 0; j < CMATRIXNBCOLUMN; j++) {
            _pix.setFillColor(getColor(_mem[i * CMATRIXNBCOLUMN + j]));
            _pix.setPosition(_pos.x + x, _pos.y + y);
            window.draw(_pix);
            x += CMATRIXGAP;
        }
        y += CMATRIXGAP;
        x = 50;
    }
    if (_bit != -1) {
        int row = _bit / CMATRIXNBCOLUMN;
        int column = _bit - (row * CMATRIXNBCOLUMN);
        _pix.setOutlineThickness(1);
        _pix.setOutlineColor(sf::Color::Red);
        _pix.setFillColor(sf::Color::Transparent);
        _pix.setPosition(_pos.x + 50 + column * CMATRIXGAP, _pos.y + (row + 1) * CMATRIXGAP);
        window.draw(_pix);
    }
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CMatrix::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 1}, "A0", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 2}, "A1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 3}, "A2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 4}, "A3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 5}, "A4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 6}, "A5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 7}, "A6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 8}, "A7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 9}, "A8", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 10}, "A9", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 11}, "A10", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 12}, "A11", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 13}, "C0", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 14}, "C1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 15}, "C2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 16}, "C3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 17}, "C4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 18}, "C5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 19}, "C6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CMATRIXY / 21 * 20}, "C7", nts::Undefined},

};
