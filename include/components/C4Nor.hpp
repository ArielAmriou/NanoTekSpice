/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Nor
*/

#ifndef COMPONENTC4NOR_HPP_
#define COMPONENTC4NOR_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4Nor: public AComponent {
        public:
            C4Nor();
            ~C4Nor() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC4NOR_HPP_ */
