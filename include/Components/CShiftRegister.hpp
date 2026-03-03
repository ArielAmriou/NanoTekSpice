/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CShiftRegister
*/

#ifndef COMPONENTCSHIFTREGISTER_HPP_
#define COMPONENTCSHIFTREGISTER_HPP_

#include "AComponent.hpp"

namespace nts {
    class CShiftRegister: public AComponent {
        public:
            CShiftRegister();
            ~CShiftRegister() = default;
            enum PinName {
                    STROBE,
                    DATA,
                    CLK,
                    Q1,
                    Q2,
                    Q3,
                    Q4,
                    VSS,
                    QS,
                    QSS,
                    Q8,
                    Q7,
                    Q6,
                    Q5,
                    ENABLE,
                    VDD,
                };
        private:
            void simulateComponent() override;
            bool handleRaseSignal();
            bool handleLowerSignal();
            bool handleData();
            static const std::vector<Pin> _defaultPins;
            static const std::vector<PinName> _outputs;
            Tristate _lastClk = Undefined;
    };
}

#endif