/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** QuitButton
*/

#include "QuitButton.hpp"

nts::QuitButton::QuitButton(std::string name, bool &push, Variables &var, sf::Vector2f pos)
    : AButton(ButtonType::QUIT), _push(push), _rec(_size)
{
    pos.y += 75;
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setPosition(pos);
    _rec.setOrigin(_size.x / 2, _size.y / 2);
    setBound(_rec.getGlobalBounds());
    _text.setFont(var._font);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setCharacterSize(20);
    _text.setString(Utils::toUpper(name));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _text.setPosition({pos.x, pos.y});
}

void nts::QuitButton::draw(sf::RenderWindow &window)
{
    if (_hover)
        _rec.setFillColor(Utils::colorOffset(DARKGREY, -50));
    else if (!_push)
        _rec.setFillColor(DARKGREY);
    else
        _rec.setFillColor(GREY);
    window.draw(_rec);
    window.draw(_text);
}

void nts::QuitButton::func()
{
    _push = !_push;
}

void nts::QuitButton::changeName(std::string name)
{
    _text.setString(Utils::toUpper(name));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
}