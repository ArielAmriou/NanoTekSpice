/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCFalse
*/

#ifndef COMPONENTCFALSE_HPP_
#define COMPONENTCFALSE_HPP_

#include "AComponent.hpp"

namespace nts {
    class CFalse: public AComponent {
        public:
            CFalse();
            ~CFalse() = default;
        private:
            nts::Tristate computeComponent(std::size_t pin) noexcept;
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCFALSE_HPP_ */
