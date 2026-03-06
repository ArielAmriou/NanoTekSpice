/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ABasicComponent
*/

#ifndef ABASICCOMPONENT_HPP_
#define ABASICCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float ABASICCOMPONENTX = 50;
    constexpr float ABASICCOMPONENTY = 70;

    class ABasicComponent: public AComponent {
        public:
            ABasicComponent(sf::Vector2f pos, sf::Font &font, const std::string &name);
        protected:
            virtual void simulateComponent() = 0;
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCAND_HPP_ */
