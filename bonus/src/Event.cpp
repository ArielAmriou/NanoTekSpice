/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Event
*/

#include "Event.hpp"
#include "Pin.hpp"
#include "Save.hpp"

void nts::Event::run(std::vector<std::function<void(sf::Event, sf::RenderWindow &)>> otherEvents)
{
    while (_variables._window.pollEvent(_event)) {
        for (auto other : otherEvents)
            other(_event, _variables._window);
        if (_event.type == sf::Event::Closed
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            _variables._window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
            Save::run(_variables._components, _variables._filename);
        componentsEvents(_variables._components);
    }
}

void nts::Event::componentsEvents(ComponentMap &components)
{
    sf::RenderWindow &window = _variables._window;
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    auto &selectChip = _variables._selectChip;

    if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        window.close();
    
    if (_event.type == sf::Event::MouseButtonPressed && _event.mouseButton.button == sf::Mouse::Left) {

        selectChip = hoverChip(components, mousePos);
        
        if (selectChip.has_value()) {
            auto &component = Utils::getComponent(components, selectChip.value().first);
            component->getChipset().setOutlineThickness(3);
            if (!selectChip.value().second.has_value()) {
                _CDragOffset = mousePos - component->getPos();
            } 
            _variables._CDragged = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && selectChip.has_value() && !selectChip.value().second.has_value()) {
        Utils::removeCon(components, selectChip.value().first);
        components.erase(selectChip.value().first);
        selectChip = std::nullopt;
    }

    if (_event.type == sf::Event::MouseButtonReleased && _event.mouseButton.button == sf::Mouse::Left) {
        if (selectChip.has_value()) {
            if (selectChip.value().second.has_value()) {
                _releaseSelectChip = hoverChip(components, mousePos);
                if (_releaseSelectChip.has_value() && _releaseSelectChip.value().second.has_value()) {
                    try {
                    Utils::getComponent(components, selectChip.value().first)
                        ->setLink(selectChip.value().second.value(),
                        *Utils::getComponent(components, _releaseSelectChip.value().first).get(),
                        _releaseSelectChip.value().second.value());
                    } catch (std::exception &e) {
                        _releaseSelectChip = std::nullopt;
                    }
                }
                _releaseSelectChip = std::nullopt;
            }
        }
        _variables._CDragged = false;
    }
}

std::optional<size_t> nts::Event::hoverPin(std::unique_ptr<IComponent> &chip, sf::Vector2f mousePos)
{
    for (size_t i = 0; i < chip->getNbPin(); i++) {
        if (chip->getNPin(i).getPin().getGlobalBounds().contains(mousePos))
            return i;
    }
    return std::nullopt;
}

std::optional<std::pair<std::string, std::optional<size_t>>> nts::Event::hoverChip(ComponentMap &list, sf::Vector2f mousePos)
{   
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        auto &component = Utils::getComponent(list, iter->first);
        if (component->getChipset().getGlobalBounds().contains(mousePos)) {
            return std::make_pair(iter->first, hoverPin(component, mousePos));
        }
    }
    return std::nullopt;
}