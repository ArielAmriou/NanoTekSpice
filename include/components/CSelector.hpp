/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CSelector
*/

#ifndef COMPONENTCSELECTOR_HPP_
#define COMPONENTCSELECTOR_HPP_

#include "AComponent.hpp"

namespace nts {
    class CSelector: public AComponent {
        public:
            CSelector();
            ~CSelector() = default;
        private:
            enum PinName {
                X0,
                X1,
                X2,
                X3,
                X4,
                X5,
                X6,
                VSS,
                X7,
                INHIBIT,
                A,
                B,
                C,
                Z,
                OE,
                VDD
            };
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCSELECTOR_HPP_ */
