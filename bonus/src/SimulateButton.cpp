/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** SimulateButton
*/

#include "SimulateButton.hpp"

nts::SimulateButton::SimulateButton(std::string name, bool &push, Variables &var, sf::Vector2f pos)
    : AButton(ButtonType::SIMULATE), _push(push), _rec(_size)
{
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setPosition(pos);
    setBound(_rec.getGlobalBounds());
    _text.setFont(var._font);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setCharacterSize(20);
    _text.setString(Utils::toUpper(name));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _text.setPosition({pos.x + _size.x / 2, pos.y + _size.y / 2});
}

void nts::SimulateButton::draw(sf::RenderWindow &window)
{
    if (_hover)
        _rec.setFillColor(Utils::colorOffset(GREY, -50));
    else if (!_push)
        _rec.setFillColor(DARKGREY);
    else
        _rec.setFillColor(GREY);
    window.draw(_rec);
    window.draw(_text);
}

void nts::SimulateButton::func()
{
    _push = !_push;
}

void nts::SimulateButton::changeName(std::string name)
{
    _text.setString(Utils::toUpper(name));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
}