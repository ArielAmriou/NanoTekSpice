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
            SimulateButton(SIMULATEBUTTONNAME[PLAY], _push[PLAY], _variables, {150, 25}),
            SimulateButton(SIMULATEBUTTONNAME[MULTIPLICATEUR], _push[MULTIPLICATEUR], _variables, {275, 25})})
{
    _rec.setPosition({0, 0});
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setOutlineThickness(3);
    _rec.setFillColor(LIGHTBLUE);
}

void nts::SimulateToolBar::draw(sf::RenderWindow &window)
{
    if (_push[PLAY] && _clk.getElapsedTime().asMilliseconds() > _simulate / SIMULATEMULTIPLICATEURVALUE[_multiplicateur]) {
        _clk.restart();
        simulate();
    }
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
    if (_push[PLAY])
        _buttons[PLAY].changeName("pause");
    else
        _buttons[PLAY].changeName("play");
    if (_push[MULTIPLICATEUR]) {
        _push[MULTIPLICATEUR] = false;
        _multiplicateur++;
        if (_multiplicateur == SimulateMultiplicateur::END)
            _multiplicateur = 0;
        _buttons[MULTIPLICATEUR].changeName(SIMULATEMULTIPLICATEURNAME[_multiplicateur]);
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