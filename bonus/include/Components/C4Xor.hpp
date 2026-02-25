/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Xor
*/

#ifndef COMPONENTC4XOR_HPP_
#define COMPONENTC4XOR_HPP_

#include "AGateComponent.hpp"

namespace nts {
    class C4Xor: public AGateComponent {
        public:
            C4Xor(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~C4Xor() = default;
        private:
            void simulateComponent() override;
    };
}

#endif /* !COMPONENTC4XOR_HPP_ */
