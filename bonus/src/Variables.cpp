/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Variables
*/

#include "Variables.hpp"
#include "ComponentFactory.hpp"

nts::Variables::Variables(sf::RenderWindow &window, ComponentMap &map, sf::Font &font, std::string filename)
    : _window(window), _font(font), _components(map), _filename(filename)
{
}

nts::Variables::Variables(Variables &var)
    : _size(var._size), _window(var._window), _font(var._font), _components(var._components)
{
}
