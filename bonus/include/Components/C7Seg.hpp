/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC7Seg
*/

#ifndef COMPONENTC7SEG_HPP_
#define COMPONENTC7SEG_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float C7SEGX = 100;
    constexpr float C7SEGY = 100;
    constexpr float C7SEGTEXTOFFSET = 20;

    class C7Seg: public AComponent {
        public:
            C7Seg(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C7Seg() = default;

            void drawComponent(sf::RenderWindow &window) override;

        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            sf::Text _7SegText;
    };
}

#endif /* !COMPONENTC7SEG_HPP_ */
