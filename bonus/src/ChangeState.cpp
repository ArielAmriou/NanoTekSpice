/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** ChangeState
*/

#include "ChangeState.hpp"
#include "Pin.hpp"

nts::ChangeState::ChangeState(Variables &var)
    : _state(Undefined), _push({true, false, false}),
    _buttons({TristateButton(Undefined, _push[Undefined + 1], var),
            TristateButton(False, _push[False + 1], var),
            TristateButton(True, _push[True + 1], var)}),
    _var(var)
{
}

void nts::ChangeState::draw(sf::RenderWindow &window)
{
    for (auto &button: _buttons)
        button.draw(window);
}

void nts::ChangeState::updateState()
{
    if (_component.has_value() && _var._components.find(_component.value()) != _var._components.end())
        Utils::getComponent(_var._components, _component.value())->getNPin(0).setValue(_state);
    else
        resetComponent();
}

void nts::ChangeState::event(sf::Event event, sf::RenderWindow &window)
{
    if (_show) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (auto &button: _buttons)
            button.click(mousePos, event);
        for (std::size_t i = 0; i < 3; i++) {
            if (_push[i] && i != _state + 1) {
                _push[_state + 1] = false;
                if (i == 1)
                    _state = False;
                else if (i == 2)
                    _state = True;
                else
                    _state = Undefined;
            }
        }
        _var._updateState = true;
    }
}

void nts::ChangeState::updateValue(std::string name)
{
    _component = name;
    auto &component = Utils::getComponent(_var._components, name);
    _state = component->getNPin(0).getValue();
    for (auto &button: _buttons)
        button.changePos({component->getPos().x + 25, component->getPos().y - 10});
}