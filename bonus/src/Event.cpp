/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Event
*/

#include "Event.hpp"

void nts::Event::run(std::vector<std::function<void(sf::Event, sf::RenderWindow &)>> otherEvents)
{
    while (_window.pollEvent(_event)) {
        for (auto other : otherEvents)
            other(_event, _window);
        if (_event.type == sf::Event::Closed
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            _window.close();
    }
}