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
    constexpr int CRAMNBLINE = 32;
    constexpr int CRAMNBCOLUMN = 32;
    constexpr int CRAMGAP = 10;
    constexpr float CRAMX = 50 + CRAMGAP * (CRAMNBCOLUMN + 2);
    constexpr float CRAMY = CRAMGAP * (CRAMNBLINE + 2);
    constexpr float CRAMTEXTOFFSET = CRAMX / 2 - (SIDEOFFSET * 4);

    class CRam: public AComponent {
        public:
            CRam(sf::Vector2f pos, sf::Font &font, const std::string &name);
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

            void drawComponent(sf::RenderWindow &window) override;

        private:
            char getChar(std::array<Tristate, BIT>);
            void simulateComponent();
            bool validAdr(int adr);
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            static const std::vector<PinName> _duals;
            static const std::vector<PinName> _address;
            std::array<std::array<Tristate, BIT>, RAMMEM> _mem;

            sf::Text _text;
            int _bit = -1;
    };
}

#endif