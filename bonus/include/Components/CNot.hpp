/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCNot
*/

#ifndef COMPONENTCNOT_HPP_
#define COMPONENTCNOT_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr int CNOTX = 50;
    constexpr int CNOTY = 50;

    class CNot: public AComponent {
        public:
            CNot(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CNot() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCNOT_HPP_ */
