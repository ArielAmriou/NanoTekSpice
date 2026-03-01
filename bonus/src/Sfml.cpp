/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include "NtsException.hpp"
#include "Utils.hpp"

nts::Sfml::Sfml(sf::Font &font, std::string filename)
    : _window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_BITS), "NanoTeckSpice", sf::Style::Close)),
     _variables(_window, _components, font, filename), _event(_variables), _line(sf::LinesStrip, 2), _rightToolBar(_variables),
     _changeState(_variables), _simulateToolBar(_variables)
{
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_rightToolBar.event(e, w);});
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_changeState.event(e, w);});
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_simulateToolBar.event(e, w);});
}

void nts::Sfml::run()
{
    while (_variables._window.isOpen()) {
        _event.run(_otherEvents);
        _variables._window.clear(DARKBLUE);
        drawComponents(_variables._components);
        drawChangeState();
        _rightToolBar.draw(_variables._window);
        _simulateToolBar.draw(_variables._window);
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
        Utils::getComponent(components, chip.first)->drawConnection(window);
    }

    for (auto &chip : components) {
        Utils::getComponent(components, chip.first)->drawLabel(window);
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

void nts::Sfml::drawChangeState()
{
    if (!_variables._selectChip.has_value()
        || _variables._selectChip.value().second.has_value()
        || (_components.find(_variables._selectChip.value().first)->second.second != "input"
        && _components.find(_variables._selectChip.value().first)->second.second != "clock")) {
        _changeState.setShow(false);
        _changeState.resetComponent();
        return;
    }
    auto &component = Utils::getComponent(_components, _variables._selectChip.value().first);

    _changeState.updateValue(*component);
    _changeState.draw(_window);
    _changeState.setShow(true);
}