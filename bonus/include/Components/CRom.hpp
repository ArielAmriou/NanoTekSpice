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
    constexpr int CROMNBLINE = 32;
    constexpr int CROMNBCOLUMN = 64;
    constexpr int CROMGAP = 10;
    constexpr float CROMX = 50 + CROMGAP * (CROMNBCOLUMN + 2);
    constexpr float CROMY = CROMGAP * (CROMNBLINE + 2);
    constexpr float CROMTEXTOFFSET = CROMX / 2 - (SIDEOFFSET * 4);

    class CRom: public AComponent {
        public:
            CRom(sf::Vector2f pos, sf::Font &font, const std::string &name);
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

            void drawComponent(sf::RenderWindow &window) override;

        private:
            void simulateComponent();
            char getChar(std::array<Tristate, BIT>);
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            static const std::vector<PinName> _outputs;
            static const std::vector<PinName> _address;
            std::array<std::array<Tristate, BIT>, ROMMEM> _mem;
            Tristate _lastClk = Undefined;

            sf::Text _text;
            int _bit = -1;
    };
}

#endif