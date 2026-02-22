/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Slider
*/

#ifndef SLIDERHPP
    #define SLIDERHPP

    #include <SFML/Graphics.hpp>

namespace nts {

    constexpr int SCROLLDELTA = -20;
    constexpr uint8_t SLIDEROPACITY = 200;

    class Slider {
        public:
            Slider(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
            ~Slider() {};

            void setMaxScroll(float size);
            void setSrollZone(sf::FloatRect zone) {_scrollZone = zone;}

            float getScroll() {return _scroll;}

            float event(sf::Event event, sf::RenderWindow &window);
            void draw(sf::RenderWindow &window);

        private:
            void handleScrollBound(float delta);
            void handleDragBound(float newPos);
            sf::Vector2f _size;
            sf::Vector2f _startPos;
            sf::RectangleShape _rec;
            sf::Color _color;
            sf::FloatRect _scrollZone;
            float _maxScroll;
            float _minScroll;
            float _scroll;
            bool _dragged = false;
            float _dragOffset;
    };
}

#endif