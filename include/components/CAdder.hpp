/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCAdder
*/

#ifndef COMPONENTC4ADDER_HPP_
#define COMPONENTC4ADDER_HPP_

#include "AComponent.hpp"
#include <list>

namespace nts {
    enum pins {
        A4,
        B3,
        A3,
        B2,
        A2,
        B1,
        A1,
        VSS,
        CI,
        S1,
        S2,
        S3,
        S4,
        CO,
        B4,
        VDD,
    };
    class CAdder: public AComponent {
        public:
            CAdder();
            ~CAdder() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
            static const std::list<int> _mustValues;
    };
}

#endif /* !COMPONENTC4ADDER_HPP_ */
