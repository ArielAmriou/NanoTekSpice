/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** SimulateToolBar
*/

#ifndef SIMULATETOOLBARHPP
    #define SIMULATETOOLBARHPP

    #include <array>
    #include "SimulateButton.hpp"
    #include "Variables.hpp"

namespace nts {

    enum SimulateMultiplicateur {
        X1,
        X2,
        X5,
        X10,
        X50,
        X100,
        X1000,
        END,
    };

    static const std::vector<std::string> SIMULATEMULTIPLICATEURNAME = {
        "x1",
        "x2",
        "x5",
        "x10",
        "x50",
        "x100",
        "x1000"
    };

    static const std::vector<std::size_t> SIMULATEMULTIPLICATEURVALUE = {
        1,
        2,
        5,
        10,
        50,
        100,
        1000
    };

    enum SimulateButtonType {
        TICK,
        PLAY,
        MULTIPLICATEUR,
        NB,
    };

    static const std::vector<std::string> SIMULATEBUTTONNAME = {
        "tick",
        "play",
        SIMULATEMULTIPLICATEURNAME[X1]
    };

    class SimulateToolBar {
        public:
            SimulateToolBar(Variables &var);
            ~SimulateToolBar() {};

            void draw(sf::RenderWindow &window);
            void event(sf::Event event, sf::RenderWindow &window);

        private:
            void simulate();
            Variables &_variables;
            sf::Vector2f _size = {400, 100};
            sf::RectangleShape _rec;
            sf::Clock _clk;
            std::array<bool, NB> _push;
            std::array<SimulateButton, NB> _buttons;
            std::size_t _tick = 0;
            std::size_t _simulate = 1000;
            std::size_t _multiplicateur = 0;
    };
}

#endif