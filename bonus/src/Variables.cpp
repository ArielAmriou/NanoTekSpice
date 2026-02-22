/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Variables
*/

#include "Variables.hpp"
#include "ComponentFactory.hpp"

nts::Variables::Variables(sf::RenderWindow &window, ComponentMap &map)
    : _window(window), _font(loadFont()), _components(map)
{
}

nts::Variables::Variables(Variables &var)
    : _size(var._size), _window(var._window), _font(var._font), _components(var._components)
{
}

sf::Font nts::Variables::loadFont()
{
    sf::Font font;

    if (!font.loadFromFile("public/Font.ttf"))
        throw FontsException();
    return font;
}