/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Xor
*/

#ifndef COMPONENTC4XOR_HPP_
#define COMPONENTC4XOR_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4Xor: public AComponent {
        public:
            C4Xor();
            ~C4Xor() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC4XOR_HPP_ */
