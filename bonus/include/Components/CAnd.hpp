/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCAnd
*/

#ifndef COMPONENTCAND_HPP_
#define COMPONENTCAND_HPP_

#include "ABasicComponent.hpp"

namespace nts {
    class CAnd: public ABasicComponent {
        public:
            CAnd(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CAnd() = default;
        private:
            void simulateComponent() override;
    };
}

#endif /* !COMPONENTCAND_HPP_ */
