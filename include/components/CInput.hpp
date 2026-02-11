/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCInput
*/

#ifndef COMPONENTCINPUT_HPP_
#define COMPONENTCINPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class CInput: public AComponent {
        public:
            CInput();
            ~CInput() = default;
            nts::Tristate compute(std::size_t pin) noexcept;
        private:
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCINPUT_HPP_ */
