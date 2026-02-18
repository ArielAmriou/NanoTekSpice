/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CDecoder
*/

#ifndef COMPONENTCDECODER_HPP_
#define COMPONENTCDECODER_HPP_

#include "AComponent.hpp"

namespace nts {
    class CDecoder: public AComponent {
        public:
            CDecoder();
            ~CDecoder() = default;

            enum PinName {
                STROBE,
                A,
                B,
                S7,
                S6,
                S5,
                S4,
                S3,
                S1,
                S2,
                S0,
                VSS,
                S13,
                S12,
                S15,
                S14,
                S9,
                S8,
                S11,
                S10,
                C,
                D,
                INHIBIT,
                VDD
            };

        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
            static const std::vector<PinName> _outputs;
            static const std::vector<PinName> _inputs;
    };
}

#endif /* !COMPONENTCDECODER_HPP_ */
