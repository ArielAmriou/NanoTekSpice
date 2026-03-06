/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCMatrix
*/

#ifndef COMPONENTCMATRIX_HPP_
#define COMPONENTCMATRIX_HPP_

#include <array>
#include "AComponent.hpp"
#include "Utils.hpp"

namespace nts {

    constexpr int MATRIXMEM = 4096;
    constexpr int CMATRIXNBLINE = 64;
    constexpr int CMATRIXNBCOLUMN = 64;
    constexpr int CMATRIXGAP = 5;
    constexpr float CMATRIXX = 50 + CMATRIXGAP * (CMATRIXNBCOLUMN + 2);
    constexpr float CMATRIXY = CMATRIXGAP * (CMATRIXNBLINE + 2);
    constexpr float CMATRIXTEXTOFFSET = CMATRIXX / 2 - (SIDEOFFSET * 4);
    constexpr int NBMATRIXADR = 12;
    constexpr int NBMATRIXCOLOR = 8;

    class CMatrix: public AComponent {
        public:
            CMatrix(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CMatrix() = default;

            void drawComponent(sf::RenderWindow &window) override;

        private:
            void simulateComponent();
            sf::Color getColor(std::array<Tristate, BIT>);
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            std::array<std::array<Tristate, BIT>, MATRIXMEM> _mem;

            sf::RectangleShape _pix;
            int _bit = -1;
    };
}

#endif /* !COMPONENTCMATRIX_HPP_ */
