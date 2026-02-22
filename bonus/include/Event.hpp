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
#include "Variables.hpp"

namespace nts {
    class Event {
        public:
            Event(Variables &var) : _variables(var) {};
            ~Event() {};

            std::optional<std::pair<std::string, std::optional<size_t>>> &getReleaseSelectChip() {return _releaseSelectChip;}
            sf::Vector2f getCDraggedOffset() {return _CDragOffset;}

            void run(std::vector<std::function<void(sf::Event, sf::RenderWindow &)>>);

        private:
            void componentsEvents(ComponentMap &list);
            std::optional<size_t> hoverPin(std::unique_ptr<IComponent> &chip, sf::Vector2f mousePos);
            std::optional<std::pair<std::string, std::optional<size_t>>> hoverChip(ComponentMap &list, sf::Vector2f mousePos);

            Variables &_variables;
            sf::Event _event;
            std::optional<std::pair<std::string, std::optional<size_t>>> _releaseSelectChip = std::nullopt;
            sf::Vector2f _CDragOffset;
    };
}

#endif
