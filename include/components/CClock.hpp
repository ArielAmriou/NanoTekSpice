/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCClock
*/

#ifndef COMPONENTCCLOCK_HPP_
#define COMPONENTCCLOCK_HPP_

#include "AComponent.hpp"

namespace nts {
    class CClock: public AComponent {
        public:
            CClock();
            ~CClock() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCCLOCK_HPP_ */
