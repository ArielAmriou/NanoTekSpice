/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Event
*/

#ifndef EVENTHPP
    #define EVENTHPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <optional>
#include "Utils.hpp"

namespace nts {
    class Event {
        public:
            Event(sf::RenderWindow &window) : _window(window) {};
            ~Event() {};

            std::optional<std::pair<std::string, std::optional<size_t>>> &getSelectChip() {return _selectChip;}
            std::optional<std::pair<std::string, std::optional<size_t>>> &getReleaseSelectChip() {return _releaseSelectChip;}
            bool getCDragged() {return _CDragged;}
            sf::Vector2f getCDraggedOffset() {return _CDragOffset;}

            void run(std::vector<std::function<void(sf::Event, sf::RenderWindow &)>>, ComponentMap &list);

        private:
            void componentsEvents(ComponentMap &list);
            std::optional<size_t> hoverPin(std::unique_ptr<IComponent> &chip, sf::Vector2f mousePos);
            std::optional<std::pair<std::string, std::optional<size_t>>> hoverChip(ComponentMap &list, sf::Vector2f mousePos);

            sf::RenderWindow &_window;
            sf::Event _event;
            std::optional<std::pair<std::string, std::optional<size_t>>> _selectChip = std::nullopt;
            std::optional<std::pair<std::string, std::optional<size_t>>> _releaseSelectChip = std::nullopt;
            bool _CDragged = false;
            sf::Vector2f _CDragOffset;
    };
}

#endif
