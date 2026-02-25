/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCClock
*/

#ifndef COMPONENTCCLOCK_HPP_
#define COMPONENTCCLOCK_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float CCLOCKX = 50;
    constexpr float CCLOCKY = 50;

    class CClock: public AComponent {
        public:
            CClock(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CClock() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCCLOCK_HPP_ */
