/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Nor
*/

#ifndef COMPONENTC4NOR_HPP_
#define COMPONENTC4NOR_HPP_

#include "AGateComponent.hpp"

namespace nts {
    class C4Nor: public AGateComponent {
        public:
            C4Nor(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C4Nor() = default;
        private:
            static const Tristate function(Tristate, Tristate);
    };
}

#endif /* !COMPONENTC4NOR_HPP_ */
