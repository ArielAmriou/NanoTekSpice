/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCOutput
*/

#ifndef COMPONENTCOUTPUT_HPP_
#define COMPONENTCOUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class COutput: public AComponent {
        public:
            COutput();
            ~COutput() = default;
            virtual nts::Tristate compute(std::size_t pin) noexcept;
        private:
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCOUTPUT_HPP_ */
