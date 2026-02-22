/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Slider
*/

#include "Slider.hpp"
#include "Utils.hpp"

nts::Slider::Slider(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
    : _size(size), _startPos(pos), _rec(_size), _color(color), _maxScroll(size.y), _minScroll(pos.y)
{
    _rec.setPosition(pos);
    _rec.setFillColor(Utils::colorOpacity(color, SLIDEROPACITY));
    _rec.setScale(1, _size.y / (_maxScroll + _size.y));
}

void nts::Slider::draw(sf::RenderWindow &window)
{
    if (_rec.getScale().y != 1)
        window.draw(_rec);
}

float nts::Slider::event(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (_scrollZone.contains(mousePos) && event.type == sf::Event::MouseWheelScrolled)
        handleScrollBound(event.mouseWheelScroll.delta * SCROLLDELTA);

    if (_rec.getGlobalBounds().contains(mousePos)) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            _dragOffset = mousePos.y - _rec.getPosition().y;
            _dragged = true;
        }
        _rec.setFillColor(_color);
    }
    else
        _rec.setFillColor(Utils::colorOpacity(_color, SLIDEROPACITY));

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        _dragged = false;
    if (_dragged)
        handleDragBound(mousePos.y - _dragOffset);
    return _scroll;
}

void nts::Slider::handleScrollBound(float delta)
{
    _scroll += delta;
    if (_scroll < _minScroll)
        _scroll = _minScroll;
    else if (_scroll > _maxScroll)
        _scroll = _maxScroll;
    _rec.setPosition(_rec.getPosition().x, _scroll * _size.y / (_maxScroll + _size.y));
}

void nts::Slider::handleDragBound(float pos)
{
    if (pos > _size.y - _size.y * _rec.getScale().y)
        pos = _size.y - _size.y * _rec.getScale().y;
    if (pos < _startPos.y)
        pos = _startPos.y;
    _scroll = pos * (_maxScroll + _size.y) / _size.y;
    _rec.setPosition(_rec.getPosition().x, pos);
}

void nts::Slider::setMaxScroll(float size)
{
    _maxScroll = size;
    _rec.setScale(1, _size.y / (_maxScroll + _size.y));
}