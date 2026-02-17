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
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCFALSE_HPP_ */
