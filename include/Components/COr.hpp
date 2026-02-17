/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCOr
*/

#ifndef COMPONENTCOR_HPP_
#define COMPONENTCOR_HPP_

#include "AComponent.hpp"

namespace nts {
    class COr: public AComponent {
        public:
            COr();
            ~COr() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCOR_HPP_ */
