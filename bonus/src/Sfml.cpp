/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include "NtsException.hpp"
#include "Utils.hpp"
#include "ComponentFactory.hpp"

nts::Sfml::Sfml()
    : _window(sf::VideoMode(_size.x, _size.y, 144), "NanoTeckSpice", sf::Style::Close),
    _event(_window)
{
    try {
        _font = loadFont();
    } catch (FontsException &e) {
        throw e;
    }
    _components.insert({"1", std::make_pair(ComponentFactory::createComponent("input", {100, 100}, _font), "input")});
    _components.insert({"2", std::make_pair(ComponentFactory::createComponent("output", {200, 100}, _font), "output")});
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
        for (auto &chip : _components) {
            Utils::getComponent(_components, chip.first)->draw(_window);
        }
        _window.display();
    }
}