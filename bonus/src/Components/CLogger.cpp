/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CLogger
*/

#include <cmath>
#include <fstream>
#include "CLogger.hpp"
#include "Utils.hpp"

nts::CLogger::CLogger(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CLOGGERX, CLOGGERY}, font, _defaultPins)
{
    _textOffset = {-CLOGGERTEXTOFFSET, 0};
    this->_nbPins = this->_pins.size();
    _loggerText.setFont(font);
    _loggerText.setCharacterSize(30);
    _loggerText.setStyle(sf::Text::Bold);
    _loggerText.setString(Utils::toUpper(""));
    sf::FloatRect rc = _loggerText.getLocalBounds();
    _loggerText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
}

void nts::CLogger::drawComponent(sf::RenderWindow &window)
{
    _loggerText.setPosition({_pos.x + _size.x / 2 + CLOGGERTEXTOFFSET, _pos.y + _size.y / 2});
    window.draw(_loggerText);
}

void nts::CLogger::writeInFile(char value)
{
    std::ofstream file("./log.bin", std::ios::app | std::ios::binary);
    
    if (file.is_open()) {
        file.put(value);
        file.close();
    }
    std::string tmp = "";
    tmp.push_back(value);
    _loggerText.setString(tmp);
    sf::FloatRect rc = _loggerText.getLocalBounds();
    _loggerText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
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
    if (undefined || append != True) {
        _loggerText.setString("");
        return;
    }
    writeInFile(value);
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CLogger::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11}, "D0", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 2}, "D1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 3}, "D2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 4}, "D3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 5}, "D4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 6}, "D5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 7}, "D6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 8}, "D7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 9}, "CLK", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CLOGGERY / 11 * 10}, "inhibit", nts::Undefined},
};
