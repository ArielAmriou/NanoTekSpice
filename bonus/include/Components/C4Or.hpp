/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Or
*/

#ifndef COMPONENTC4OR_HPP_
#define COMPONENTC4OR_HPP_

#include "AGateComponent.hpp"

namespace nts {
    class C4Or: public AGateComponent {
        public:
            C4Or(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C4Or() = default;
        private:
            void simulateComponent() override;
    };
}

#endif /* !COMPONENTC4NOR_HPP_ */
