/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Variables
*/

#ifndef VARIABLESHPP
    #define VARIABLESHPP

    #include <SFML/Graphics.hpp>
    #include <optional>
    #include "Utils.hpp"

namespace nts
{
    class Variables {
        public:
            Variables(sf::RenderWindow &window, ComponentMap &);
            Variables(Variables &var);

            sf::Vector2u _size = {WINDOW_SIZE_X, WINDOW_SIZE_Y};
            sf::RenderWindow &_window;
            sf::Font _font;
            ComponentMap &_components;
            std::optional<std::pair<std::string, std::optional<size_t>>> _selectChip = std::nullopt;
            bool _CDragged = false;
            bool _rightToolBar = true;

        private:
            sf::Font loadFont();
    };
}

#endif
