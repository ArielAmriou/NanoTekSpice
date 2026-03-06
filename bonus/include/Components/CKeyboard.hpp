/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCKeyboard
*/

#ifndef COMPONENTCKEYBOARD_HPP_
#define COMPONENTCKEYBOARD_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float CKEYBOARDX = 100;
    constexpr float CKEYBOARDY = 150;

    class CKeyboard: public AComponent {
        public:
            CKeyboard(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CKeyboard() = default;
        private:
            void setPins();
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            static const std::vector<std::tuple<sf::Keyboard::Key, char, char>> _inputs;
        };
}

#endif /* !COMPONENTCKeyboard_HPP_ */
