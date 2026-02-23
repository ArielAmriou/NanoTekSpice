/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** SimulateToolBar
*/

#include "SimulateToolBar.hpp"
#include "Utils.hpp"
#include "ComponentButton.hpp"

nts::SimulateToolBar::SimulateToolBar(Variables &var)
    : _variables(var), _rec(_size),
    _buttons({SimulateButton(SIMULATEBUTTONNAME[TICK], _push[TICK], _variables, {25, 25}),
            SimulateButton(SIMULATEBUTTONNAME[PLAY], _push[PLAY], _variables, {150, 25})})
{
    _rec.setPosition({0, 0});
    _rec.setFillColor(DARKGREY);
}

void nts::SimulateToolBar::draw(sf::RenderWindow &window)
{
    if (_push[PLAY])
        simulate();
    window.draw(_rec);
    for (auto &button : _buttons)
        button.draw(window);
}

void nts::SimulateToolBar::event(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    for (auto &button : _buttons)
        button.click(mousePos, event);
    if (_push[TICK]) {
        simulate();
        for (auto &push: _push)
            push = false;
    }
}


void nts::SimulateToolBar::simulate()
{
    _tick++;
    auto iter = _variables._components.begin();
    while (iter != _variables._components.end()) {
        iter->second.first->simulate(_tick);
        iter++;
    }
}