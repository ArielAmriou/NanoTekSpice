/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Or
*/

#ifndef COMPONENTC4OR_HPP_
#define COMPONENTC4OR_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4Or: public AComponent {
        public:
            C4Or();
            ~C4Or() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC4OR_HPP_ */
