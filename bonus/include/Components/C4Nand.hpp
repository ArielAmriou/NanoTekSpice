/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Nand
*/

#ifndef COMPONENTC4NAND_HPP_
#define COMPONENTC4NAND_HPP_

#include "AGateComponent.hpp"

namespace nts {
    class C4Nand: public AGateComponent {
        public:
            C4Nand(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C4Nand() = default;
    };
}

#endif /* !COMPONENTC4NAND_HPP_ */
