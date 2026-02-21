/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Connection
*/

#include "Connection.hpp"
#include "Pin.hpp"

void nts::Connection::draw(sf::RenderWindow &window, sf::Vector2f pos)
{
    sf::Color color(sf::Color::White);
    Tristate state = _component.get().getNPin(_pin).getValue();

    if (state == False)
        color = sf::Color::Red;
    if (state == True)
        color = sf::Color::Green;
    _line[0].position = pos;
    _line[0].color = color;
    _line[1].position = _component.get().getNPinPos(_pin);
    _line[1].color = color;
    window.draw(_line);
}