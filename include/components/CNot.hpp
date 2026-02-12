/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCNot
*/

#ifndef COMPONENTCNOT_HPP_
#define COMPONENTCNOT_HPP_

#include "AComponent.hpp"

namespace nts {
    class CNot: public AComponent {
        public:
            CNot();
            ~CNot() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCNOT_HPP_ */
