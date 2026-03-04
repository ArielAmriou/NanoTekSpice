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

    constexpr float CDUALFLIPFLOPX = 50;
    constexpr float CDUALFLIPFLOPY = 150;

    class CDualFlipFlop: public AComponent {
        public:
            CDualFlipFlop(sf::Vector2f pos, sf::Font &font, const std::string &name);
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
            void simulateComponent() override;
            bool handleAsync(PinName q, PinName nq,
                PinName set, PinName reset);
            void simulateFlipFlop(PinName q, PinName nq,
                PinName clk, PinName data, Tristate &lastClk);
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            Tristate _lastClk1 = Undefined;
            Tristate _lastClk2 = Undefined;
    };
}

#endif
