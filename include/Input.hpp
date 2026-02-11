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
            virtual nts::Tristate compute(std::size_t pin) noexcept;
        private:
            static const std::vector<std::pair<std::optional<std::string>, nts::Mode>> _default_pins;
    };
}


#endif /* !COMPONENTINPUT_HPP_ */
