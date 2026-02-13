/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCXor
*/

#ifndef COMPONENTCXOR_HPP_
#define COMPONENTCXOR_HPP_

#include "AComponent.hpp"

namespace nts {
    class CXor: public AComponent {
        public:
            CXor();
            ~CXor() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCXOR_HPP_ */
