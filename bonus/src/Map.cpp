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
    _recMap.setOutlineColor(sf::Color::Black);
    _recMap.setFillColor(nts::LIGHTBLUE);
    _recScreen.setOrigin(_sizeScreen.x / 2, _sizeScreen.y / 2);
    _recScreen.setFillColor(sf::Color::Transparent);
    _recScreen.setOutlineThickness(2);
    _recScreen.setOutlineColor(nts::RED);
    _recComponent.setFillColor(nts::DARKGREY);
}

void nts::Map::draw(sf::RenderWindow &window)
{
    if (!_var._showMap)
        return;
    window.draw(_recMap);
    _recScreen.setPosition(
        OFFSETRATIO_X - POSRATIO_X(_var._offset.x),
        OFFSETRATIO_Y - POSRATIO_Y(_var._offset.y)
    );
    window.draw(_recScreen);
    for (auto iter = _var._components.begin(); iter != _var._components.end(); iter++) {
        auto tmpSize = iter->second.first->getSize();
        sf::Vector2f halfTmpSize = {tmpSize.x / 2, tmpSize.y / 2};
        sf::Vector2f size = {tmpSize.x * _sizeScreen.x / WINDOW_SIZE_X, tmpSize.y * _sizeScreen.y / WINDOW_SIZE_Y};
        auto tmpPos = iter->second.first->getPos() + halfTmpSize - sf::Vector2f(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2) - _var._offset;
        _recComponent.setSize(size);
        _recComponent.setOrigin(size.x / 2, size.y / 2);
        _recComponent.setPosition(
            OFFSETRATIO_X + POSRATIO_X(tmpPos.x),
            OFFSETRATIO_Y + POSRATIO_Y(tmpPos.y)
        );
        window.draw(_recComponent);
    }
}