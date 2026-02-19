/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCRom
*/

#ifndef COMPONENTCROM_HPP_
#define COMPONENTCROM_HPP_

#include <array>
#include "AComponent.hpp"
#include "Utils.hpp"

namespace nts {

    constexpr int ROMMEM = 2048;

    class CRom: public AComponent {
        public:
            CRom();
            ~CRom() = default;
            enum PinName {
                A7,
                A6,
                A5,
                A4,
                A3,
                A2,
                A1,
                A0,
                Q0,
                Q1,
                Q2,
                VSS,
                Q3,
                Q4,
                Q5,
                Q6,
                Q7,
                CE,
                A10,
                OE,
                VPP,
                A9,
                A8,
                VCC,
            };
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
            static const std::vector<PinName> _outputs;
            static const std::vector<PinName> _address;
            std::array<std::array<Tristate, BIT>, ROMMEM> _mem;
            Tristate _lastClk = Undefined;
    };
}

#endif