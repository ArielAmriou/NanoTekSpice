/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CDualFlipFlop
*/

#ifndef COMPONENTCFLIPFLOP_HPP_
    #define COMPONENTCFLIPFLOP_HPP_

#include <array>
#include "APartComponent.hpp"

namespace nts {

    constexpr std::size_t CFLIPFLOPNBPART = 2;
    constexpr std::size_t CFLIPFLOPNBIN = 4;
    constexpr std::size_t CFLIPFLOPNBOUT = 2;

    class CDualFlipFlop: public APartComponent {
        public:
            CDualFlipFlop();
            ~CDualFlipFlop() = default;
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

        protected:
            const std::vector<std::size_t> getInputPins() override
                {return _inputs;}
            const std::vector<std::size_t> getOutputPins() override
                {return _outputs;}
            void computePart(std::size_t partId) override;

        private:
            bool handleAsync(PinName q, PinName nq,
                PinName set, PinName reset);
            void simulateFlipFlop(PinName q, PinName nq,
                PinName clk, PinName data, Tristate &lastClk);
            static const std::vector<Pin> _defaultPins;
            static const std::vector<std::size_t> _inputs;
            static const std::vector<std::size_t> _outputs;
            Tristate _lastClk1 = Undefined;
            Tristate _lastClk2 = Undefined;
            std::array<std::size_t, 2> _tickFlipFlop = {0, 0};
    };
}

#endif
