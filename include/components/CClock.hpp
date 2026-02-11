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
            nts::Tristate compute(std::size_t pin) noexcept;
        private:
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCCLOCK_HPP_ */
