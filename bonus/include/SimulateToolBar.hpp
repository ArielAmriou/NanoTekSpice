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

    enum SimulateButtonType {
        TICK,
        PLAY,
        NB,
    };

    static const std::vector<std::string> SIMULATEBUTTONNAME = {
        "tick",
        "play"
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
            sf::Vector2f _size = {275, 100};
            sf::RectangleShape _rec;
            std::array<bool, NB> _push;
            std::array<SimulateButton, NB> _buttons;
            std::size_t _tick = 0;
    };
}

#endif