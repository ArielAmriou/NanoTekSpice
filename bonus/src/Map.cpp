/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Map
*/

#include "Map.hpp"

nts::Map::Map(Variables &var)
    : _var(var), _recMap(_sizeMap), _recScreen(_sizeScreen)
{
    _recMap.setOrigin(0, _sizeMap.y);
    _recMap.setPosition(10, WINDOW_SIZE_Y - 10);
    _recMap.setOutlineThickness(3);
    _recMap.setOutlineColor(nts::RED);
    _recMap.setFillColor(sf::Color::Transparent);
    _recScreen.setOrigin(_sizeScreen.x / 2, _sizeScreen.y / 2);
    _recScreen.setPosition(100, WINDOW_SIZE_Y - 100);
    _recScreen.setFillColor(nts::RED);
}

void nts::Map::draw(sf::RenderWindow &window)
{
    if (!_var._showMap)
        return;
    _recScreen.setPosition(
        10 + _sizeMap.x / 2 + _var._offset.x * _sizeMap.x / (2 * MAXOFFSET_X + WINDOW_SIZE_X),
        WINDOW_SIZE_Y - 10 - _sizeMap.y / 2 + _var._offset.y * _sizeMap.y / (2 * MAXOFFSET_Y + WINDOW_SIZE_Y)
    );
    window.draw(_recScreen);
    window.draw(_recMap);
}