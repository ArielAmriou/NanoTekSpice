/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Utils
*/

#ifndef UTILSHPP
    #define UTILSHPP

    #include <SFML/Graphics.hpp>
    #include <string>

namespace nts {

    inline const sf::Color GREY = sf::Color(150, 150, 150);
    inline const sf::Color DARKGREY = sf::Color(50, 50, 50);
    inline const sf::Color DARKBLUE = sf::Color(0, 0, 139);
    inline const sf::Color WHITHETHROUGH = sf::Color(255, 255, 255, 200);

    class Utils {
        public:
            static std::string toUpper(const std::string &);
            static sf::Color colorOffset(const sf::Color &rec, int offset);
            static sf::Color colorOpacity(const sf::Color &rec, int opacity);
    };
}

#endif