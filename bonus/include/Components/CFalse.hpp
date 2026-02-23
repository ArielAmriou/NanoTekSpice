/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCFalse
*/

#ifndef COMPONENTCFALSE_HPP_
#define COMPONENTCFALSE_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr int CFALSEX = 50;
    constexpr int CFALSEY = 70;

    class CFalse: public AComponent {
        public:
            CFalse(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CFalse() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCFALSE_HPP_ */
