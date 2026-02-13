/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCAdder
*/

#ifndef COMPONENTC4ADDER_HPP_
#define COMPONENTC4ADDER_HPP_

#include "AComponent.hpp"

namespace nts {
    class CAdder: public AComponent {
        public:
            CAdder();
            ~CAdder() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC4ADDER_HPP_ */
