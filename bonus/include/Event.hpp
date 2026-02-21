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

namespace nts {
    class Event {
        public:
            Event(sf::RenderWindow &window) : _window(window) {};
            ~Event() {};

            void run(std::vector<std::function<void(sf::Event, sf::RenderWindow &)>>);

        private:
            sf::RenderWindow &_window;
            sf::Event _event;
    };
}

#endif
