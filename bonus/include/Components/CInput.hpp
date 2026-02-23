/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCInput
*/

#ifndef COMPONENTCINPUT_HPP_
#define COMPONENTCINPUT_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr int CINPUTX = 50;
    constexpr int CINPUTY = 50;

    class CInput: public AComponent {
        public:
            CInput(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CInput() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCINPUT_HPP_ */
