/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Map
*/

#ifndef MAPHPP
    #define MAPHPP

#include <SFML/Graphics.hpp>
#include "Utils.hpp"
#include "Variables.hpp"

namespace nts {
    class Map {

        public:
            Map(Variables &var);
            ~Map() {};

            void draw(sf::RenderWindow &window);

        private:
            Variables &_var;
            sf::Vector2f _sizeMap = {WINDOW_SIZE_X / 10, WINDOW_SIZE_Y / 10};
            sf::RectangleShape _recMap;
            sf::Vector2f _sizeScreen = {_sizeMap.x * WINDOW_SIZE_X / (2 * MAXOFFSET_X + WINDOW_SIZE_X), _sizeMap.y * WINDOW_SIZE_Y / (2 * MAXOFFSET_Y + WINDOW_SIZE_Y)};
            sf::RectangleShape _recScreen;
    };
}

#endif