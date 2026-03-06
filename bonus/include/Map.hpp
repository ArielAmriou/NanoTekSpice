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

    constexpr float SIZEMAP_X = WINDOW_SIZE_X / 10;
    constexpr float SIZEMAP_Y = WINDOW_SIZE_Y / 10;
    constexpr float SIZERATIO_X(float value) {return value * WINDOW_SIZE_X / (2 * MAXOFFSET_X + WINDOW_SIZE_X);}
    constexpr float SIZERATIO_Y(float value) {return value * WINDOW_SIZE_Y / (2 * MAXOFFSET_Y + WINDOW_SIZE_Y);}
    constexpr float POSRATIO_X(float value) {return value * SIZEMAP_X / (2 * MAXOFFSET_X + WINDOW_SIZE_X);}
    constexpr float POSRATIO_Y(float value) {return value * SIZEMAP_Y / (2 * MAXOFFSET_Y + WINDOW_SIZE_Y);}
    constexpr float OFFSETRATIO_X = 10 + SIZEMAP_X / 2;
    constexpr float OFFSETRATIO_Y = WINDOW_SIZE_Y - 10 - SIZEMAP_Y / 2;

    class Map {

        public:
            Map(Variables &var);
            ~Map() {};

            void draw(sf::RenderWindow &window);

        private:
            Variables &_var;
            sf::Vector2f _sizeMap = {SIZEMAP_X, SIZEMAP_Y};
            sf::RectangleShape _recMap;
            sf::Vector2f _sizeScreen = {SIZERATIO_X(_sizeMap.x), SIZERATIO_Y(_sizeMap.y)};
            sf::RectangleShape _recScreen;
            sf::RectangleShape _recComponent;
    };
}

#endif