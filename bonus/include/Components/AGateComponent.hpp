/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AGateComponent
*/

#ifndef AGATECOMPONENT_HPP_
#define AGATECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float AGATECOMPONENTX = 75;
    constexpr float AGATECOMPONENTY = 150;

    class AGateComponent: public AComponent {
        public:
            AGateComponent(sf::Vector2f pos, sf::Font &font, const std::string &name);
        protected:
            virtual void simulateComponent() = 0;
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCAND_HPP_ */
