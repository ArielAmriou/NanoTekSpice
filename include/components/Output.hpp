/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentOutput
*/

#ifndef COMPONENTOUTPUT_HPP_
#define COMPONENTOUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class Output: public AComponent {
        public:
            Output();
            ~Output() = default;
            virtual nts::Tristate compute(std::size_t pin) noexcept;
        private:
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTOUTPUT_HPP_ */
