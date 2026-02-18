/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CDualFlipFlop
*/

#ifndef COMPONENTCFLIPFLOP_HPP_
    #define COMPONENTCFLIPFLOP_HPP_

#include "AComponent.hpp"

namespace nts {
    class CDualFlipFlop: public AComponent {
        public:
            CDualFlipFlop();
            ~CDualFlipFlop() = default;

        private:
            enum PinName {
                Q1,
                Q_1,
                CLK1,
                R1,
                D1,
                S1,
                VSS,
                S2,
                D2,
                R2,
                CLK2,
                Q_2,
                Q2,
                VDD,
            };
            Tristate simulateFilpFlop(Tristate, Tristate, Tristate);
            Tristate simulateCLock(Tristate, Tristate, Tristate, Tristate);
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
            Tristate _lastClk1 = Undefined;
            Tristate _lastClk2 = Undefined;
    };
}

#endif
