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
    _font(loadFont()), _event(_window), _line(sf::LinesStrip, 2), _rightToolBar(_size, _font)
{
    _components.insert({"1", std::make_pair(ComponentFactory::createComponent("input", {100, 100}, _font), "input")});
    _components.insert({"2", std::make_pair(ComponentFactory::createComponent("output", {200, 100}, _font), "output")});
    _components.insert({"3", std::make_pair(ComponentFactory::createComponent("input", {300, 100}, _font), "input")});
    _components.insert({"4", std::make_pair(ComponentFactory::createComponent("output", {400, 100}, _font), "output")});
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_rightToolBar.event(e, w);});
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
        _event.run(_otherEvents, _components);
        _window.clear(DARKBLUE);
        drawComponents();
        _rightToolBar.draw(_window);
        _window.display();
    }
}

void nts::Sfml::drawComponents()
{
    sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
    auto selectChip = _event.getSelectChip();

    for (auto &chip : _components) {
        Utils::getComponent(_components, chip.first)->draw(_window);
    }

    for (auto &chip : _components) {
        Utils::getComponent(_components, chip.first)->drawPin(_window);
    }

    if (selectChip.has_value()) {
        auto &component = Utils::getComponent(_components, selectChip.value().first);
        if (_event.getCDragged()) {
            if (!selectChip.value().second.has_value()) {
                component->setPos(mousePos - _event.getCDraggedOffset() + sf::Vector2f(component->getSize().x / 2, component->getSize().y / 2));
            } else {
                _line[0] = component->getNPinPos(selectChip.value().second.value());
                _line[1] = mousePos;
                _window.draw(_line);
            }
        }
        if (!selectChip.value().second.has_value()) {
            sf::RectangleShape &rec = component->getChipset();
            rec.setOutlineThickness(6);
            rec.setFillColor(Utils::colorOffset(rec.getFillColor(), -50));
        }
    }
}