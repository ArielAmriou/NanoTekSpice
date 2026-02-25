/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCTrue
*/

#ifndef COMPONENTCTRUE_HPP_
#define COMPONENTCTRUE_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float CTRUEX = 50;
    constexpr float CTRUEY = 70;

    class CTrue: public AComponent {
        public:
            CTrue(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CTrue() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCTRUE_HPP_ */
