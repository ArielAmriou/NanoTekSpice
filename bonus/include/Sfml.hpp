/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Sfml
*/

#ifndef SFMLHPP
    #define SFMLHPP

#include <SFML/Graphics.hpp>
#include "Event.hpp"

namespace nts
{
    constexpr int EPISUCCESS = 0;
    constexpr int EPIERROR = 84;
    inline const sf::Color DARKBLUE = sf::Color(0, 0, 139);

    class Sfml {
        public:
            Sfml();
            ~Sfml() {};

            void run();

        private:
            sf::Font loadFont();
            sf::Vector2u _size = {1778, 1000};
            sf::RenderWindow _window;
            sf::Font _font;
            Event _event;
            std::vector<std::function<void (sf::Event, sf::RenderWindow &)>> _otherEvents;
    };
}

#endif