/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCRam
*/

#ifndef COMPONENTCRAM_HPP_
#define COMPONENTCRAM_HPP_

#include <array>
#include "AComponent.hpp"
#include "Utils.hpp"

namespace nts {

    constexpr int RAMMEM = 1024;

    class CRam: public AComponent {
        public:
            CRam();
            ~CRam() = default;
            enum PinName {
                A7,
                A6,
                A5,
                A4,
                A3,
                A2,
                A1,
                A0,
                DQ0,
                DQ1,
                DQ2,
                VSS,
                DQ3,
                DQ4,
                DQ5,
                DQ6,
                DQ7,
                CE,
                NC,
                OE,
                WE,
                A9,
                A8,
                VCC,
            };
        private:
            void simulateComponent();
            bool validAdr(int adr);
            static const std::vector<Pin> _defaultPins;
            static const std::vector<PinName> _duals;
            static const std::vector<PinName> _address;
            std::array<std::array<Tristate, BIT>, RAMMEM> _mem;
    };
}

#endif