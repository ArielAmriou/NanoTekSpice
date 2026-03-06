/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C7Seg
*/

#include <cmath>
#include <iomanip>
#include "C7Seg.hpp"
#include "Utils.hpp"

nts::C7Seg::C7Seg(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {C7SEGX, C7SEGX}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
    _textOffset = {-C7SEGTEXTOFFSET, 0};
    _7SegText.setFont(font);
    _7SegText.setCharacterSize(30);
    _7SegText.setStyle(sf::Text::Bold);
    _7SegText.setString(Utils::toUpper(""));
    sf::FloatRect rc = _7SegText.getLocalBounds();
    _7SegText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
}

void nts::C7Seg::drawComponent(sf::RenderWindow &window)
{
    _7SegText.setPosition({_pos.x + _size.x / 2 + C7SEGTEXTOFFSET, _pos.y + _size.y / 2});
    window.draw(_7SegText);
}

void nts::C7Seg::simulateComponent()
{
    int value = 0;

    for (std::size_t i = 0; i < 4; i++) {
        Tristate state = _pins[i].getValue();
        if (state == Undefined) {
            _7SegText.setString(Utils::toUpper(""));
            return;
        }
        value += state * static_cast<int>(std::pow(2, i));
    }
    std::stringstream stream;
    stream << std::hex << value;
    _7SegText.setString(Utils::toUpper(stream.str()));
    sf::FloatRect rc = _7SegText.getLocalBounds();
    _7SegText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::C7Seg::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, C7SEGY / 5 * 1}, "B0", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C7SEGY / 5 * 2}, "B1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C7SEGY / 5 * 3}, "B2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, C7SEGY / 5 * 4}, "B3", nts::Undefined}

};
