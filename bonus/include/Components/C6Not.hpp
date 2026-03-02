/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC6Not
*/

#ifndef COMPONENTC6NOT_HPP_
#define COMPONENTC6NOT_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float C6NOTX = 75;
    constexpr float C6NOTY = 150;

    class C6Not: public AComponent {
        public:
            C6Not(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C6Not() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTC6NOT_HPP_ */
