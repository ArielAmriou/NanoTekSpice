/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC4Nand
*/

#ifndef COMPONENTC4NAND_HPP_
#define COMPONENTC4NAND_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4Nand: public AComponent {
        public:
            C4Nand();
            ~C4Nand() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC4NAND_HPP_ */
