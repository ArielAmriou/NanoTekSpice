/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** TristateButton
*/

#include "TristateButton.hpp"

nts::TristateButton::TristateButton(Tristate state, bool &push, Variables &var)
    : AButton(ButtonType::TRISTATE), _state(state), _push(push), _rec(_size), _color(TRISTATECOLOR[_state + 1])
{
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setOrigin(_size.x / 2, _size.y);
    setBound(_rec.getGlobalBounds());
    _text.setFont(var._font);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setCharacterSize(15);
    _text.setString(Utils::toUpper(TRISTATENAME[_state + 1]));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
}

void nts::TristateButton::changePos(sf::Vector2f newPos)
{
    sf::Vector2f pos = {newPos.x + _size.x * static_cast<float>(_state), newPos.y};
    
    _rec.setPosition(pos);
    setBound(_rec.getGlobalBounds());
    _text.setPosition(pos.x, pos.y - _size.y / 2);
}

void nts::TristateButton::draw(sf::RenderWindow &window)
{
    if (_hover || _push)
        _rec.setFillColor(_color);
    else
        _rec.setFillColor(DARKGREY);
    window.draw(_rec);
    window.draw(_text);
}

void nts::TristateButton::func()
{
    _push = true;
}