/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include "NtsException.hpp"
#include "Utils.hpp"
#include "Pin.hpp"

nts::Sfml::Sfml(sf::Font &font, std::string filename)
    : _window(sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, WINDOW_BITS), "NanoTeckSpice", sf::Style::Close | sf::Style::Resize)),
     _variables(_window, _components, font, filename), _event(_variables), _line(sf::LinesStrip, 2), _rightToolBar(_variables),
     _changeState(_variables), _simulateToolBar(_variables),
     _gameView(sf::FloatRect(0.0, 0.0, WINDOW_SIZE_X, WINDOW_SIZE_Y))
{
    _window.setView(_gameView);
    _background.setSize({WINDOW_SIZE_X, WINDOW_SIZE_Y});
    _background.setFillColor(DARKBLUE);
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_rightToolBar.event(e, w);});
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_changeState.event(e, w);});
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow& w) {_simulateToolBar.event(e, w);});
    _otherEvents.push_back([this](sf::Event e, sf::RenderWindow &w) {handleResize(e, w);});
}

void nts::Sfml::run()
{
    auto &window = _variables._window;

    while (window.isOpen()) {
        _event.run(_otherEvents);
        window.clear(sf::Color::Black);
        window.setView(_gameView);
        window.draw(_background);
        drawComponents(_variables._components);
        drawChangeState();
        _rightToolBar.draw(window);
        _simulateToolBar.draw(window);
        window.display();
    }
}

void nts::Sfml::drawComponents(ComponentMap &components)
{
    sf::RenderWindow &window = _variables._window;
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), _gameView);
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
                sf::Color color(sf::Color::White);
                _line[0] = component->getNPinPos(selectChip.value().second.value());
                _line[1] = mousePos;
                if (component->getNPin(selectChip.value().second.value()).getValue() == nts::Tristate::True)
                    color = nts::GREEN;
                if (component->getNPin(selectChip.value().second.value()).getValue() == nts::Tristate::False)
                    color = nts::RED;
                _line[0].color = color;
                _line[1].color = color;
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

void nts::Sfml::handleResize(sf::Event event, sf::RenderWindow &window)
{
    if (event.type != sf::Event::Resized)
        return;

    const float gameW = static_cast<float>(WINDOW_SIZE_X);
    const float gameH = static_cast<float>(WINDOW_SIZE_Y);
    float windowRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
    float viewRatio   = gameW / gameH;
    sf::Vector2f size = {1, 1};
    sf::Vector2f pos = {0, 0};

    if (windowRatio >= viewRatio) {
        size.x = viewRatio / windowRatio;
        pos.x  = (1.0 - size.x) / 2.0;
    } else {
        size.y = windowRatio / viewRatio;
        pos.y  = (1.0 - size.y) / 2.0;
    }
    _gameView.setViewport(sf::FloatRect(pos.x, pos.y, size.x, size.y));
    window.setView(_gameView);
}
