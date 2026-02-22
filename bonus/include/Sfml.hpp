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
#include "Utils.hpp"
#include "RightToolBar.hpp"

namespace nts
{
    constexpr int EPISUCCESS = 0;
    constexpr int EPIERROR = 84;

    class Sfml {
        public:
            Sfml();
            ~Sfml() {};

            void run();

        private:
            void drawComponents();
            sf::Font loadFont();
            sf::Vector2u _size = {1778, 1000};
            sf::RenderWindow _window;
            sf::Font _font;
            Event _event;
            std::vector<std::function<void (sf::Event, sf::RenderWindow &)>> _otherEvents;
            ComponentMap _components;
            sf::VertexArray _line;
            RightToolBar _rightToolBar;
    };
}

#endif