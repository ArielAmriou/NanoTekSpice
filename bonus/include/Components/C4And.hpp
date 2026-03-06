/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4And
*/

#ifndef COMPONENTC4AND_HPP_
#define COMPONENTC4AND_HPP_

#include "AGateComponent.hpp"

namespace nts {
    class C4And: public AGateComponent {
        public:
            C4And(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C4And() = default;
    };
}

#endif /* !COMPONENTC4AND_HPP_ */
