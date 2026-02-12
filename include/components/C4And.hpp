/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4And
*/

#ifndef COMPONENTC4AND_HPP_
#define COMPONENTC4AND_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4And: public AComponent {
        public:
            C4And();
            ~C4And() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC4AND_HPP_ */
