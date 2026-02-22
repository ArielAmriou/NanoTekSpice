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
    #include <map>
    #include <memory>
    #include "IComponent.hpp"

    #include <iostream>
    #define DEBUG(value) std::cout << "\e[0;35m" << "DEBUG: " <<  "\e[0;37m" << "\t" << value << std::endl;

namespace nts {

    // SFML
    inline const sf::Color GREY = sf::Color(150, 150, 150);
    inline const sf::Color DARKGREY = sf::Color(50, 50, 50);
    inline const sf::Color DARKBLUE = sf::Color(0, 0, 139);
    inline const sf::Color WHITHETHROUGH = sf::Color(255, 255, 255, 200);

    constexpr int BIT = 8;

    using ComponentMap = std::map<std::string, std::pair<
        std::unique_ptr<nts::IComponent>, std::string>>;

    class Utils {
        public:
            static std::unique_ptr<nts::IComponent> &getComponent(ComponentMap &, std::string);
            static Tristate halfAdder(const Tristate a,
                const Tristate b, Tristate &carry);
            static Tristate fullAdder(const Tristate a,
                const Tristate b, Tristate &carry);
            static void removeCon(ComponentMap &components, std::string name);

            // SFML
            static std::string toUpper(const std::string &);
            static sf::Color colorOffset(const sf::Color &rec, int offset);
            static sf::Color colorOpacity(const sf::Color &rec, int opacity);
    };
}

#endif