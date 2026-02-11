/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentInput
*/

#ifndef COMPONENTINPUT_HPP_
#define COMPONENTINPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class Input: public AComponent {
        public:
            Input();
            ~Input() = default;
            nts::Tristate compute(std::size_t pin) noexcept;

        private:
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTINPUT_HPP_ */
