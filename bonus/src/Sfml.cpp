/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include "NtsException.hpp"
#include "Utils.hpp"

nts::Sfml::Sfml()
    : _window(sf::VideoMode(_size.x, _size.y, 144), "NanoTeckSpice", sf::Style::Close),
    _event(_window)
{
    try {
        _font = loadFont();
    } catch (FontsException &e) {
        throw e;
    }
}

sf::Font nts::Sfml::loadFont()
{
    sf::Font font;

    if (!font.loadFromFile("public/Font.ttf"))
        throw FontsException();
    return font;
}

void nts::Sfml::run()
{
    while (_window.isOpen()) {
        _event.run(_otherEvents);
        _window.clear(DARKBLUE);
        _window.display();
    }
}