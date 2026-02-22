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
    : _window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_BITS), "NanoTeckSpice", sf::Style::Close)),
     _variables(_window, _components), _event(_variables), _line(sf::LinesStrip, 2), _rightToolBar(_variables)
{
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_rightToolBar.event(e, w);});
}

void nts::Sfml::run()
{
    while (_variables._window.isOpen()) {
        _event.run(_otherEvents);
        _variables._window.clear(DARKBLUE);
        drawComponents(_variables._components);
        _rightToolBar.draw(_variables._window);
        _variables._window.display();
    }
}

void nts::Sfml::drawComponents(ComponentMap &components)
{
    sf::RenderWindow &window = _variables._window;
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    auto selectChip = _variables._selectChip;

    for (auto &chip : components) {
        Utils::getComponent(components, chip.first)->draw(window);
    }

    for (auto &chip : components) {
        Utils::getComponent(components, chip.first)->drawPin(window);
    }

    if (selectChip.has_value()) {
        auto &component = Utils::getComponent(components, selectChip.value().first);
        if (_variables._CDragged) {
            if (!selectChip.value().second.has_value()) {
                component->setPos(mousePos - _event.getCDraggedOffset() + sf::Vector2f(component->getSize().x / 2, component->getSize().y / 2));
            } else {
                _line[0] = component->getNPinPos(selectChip.value().second.value());
                _line[1] = mousePos;
                window.draw(_line);
            }
        }
        if (!selectChip.value().second.has_value()) {
            sf::RectangleShape &rec = component->getChipset();
            rec.setOutlineThickness(6);
            rec.setFillColor(Utils::colorOffset(rec.getFillColor(), -50));
        }
    }
}