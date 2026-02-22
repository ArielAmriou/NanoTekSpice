/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"
#include "Utils.hpp"

void nts::Pin::setConnection(
    std::reference_wrapper<IComponent> component, std::size_t pin)
{
    _con.emplace(Connection(component, pin));
}

nts::Pin &nts::Pin::operator=(const nts::Pin &right) {
    this->_mode = right._mode;
    this->_value = right._value;
    this->_circle = right._circle;
    this->_pos = right._pos;
    return *this;
};

void nts::Pin::draw(sf::RenderWindow &window, sf::Vector2f pos)
{
    sf::Color color(sf::Color::Black);

    if (_value == False)
        color = sf::Color::Red;
    if (_value == True)
        color = sf::Color::Green;
    _circle.setPosition({_pos.x + pos.x, _pos.y + pos.y});
    _circle.setFillColor(color);
    window.draw(_circle);
    if (_con.has_value())
        _con.value().draw(window, {_pos.x + pos.x, _pos.y + pos.y});
}