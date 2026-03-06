/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCXor
*/

#ifndef COMPONENTCXOR_HPP_
#define COMPONENTCXOR_HPP_

#include "ABasicComponent.hpp"

namespace nts {
    class CXor: public ABasicComponent {
        public:
            CXor(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CXor() = default;
        private:
            void simulateComponent() override;
    };
}

#endif /* !COMPONENTCXOR_HPP_ */
