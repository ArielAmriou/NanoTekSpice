/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** SimulateButton
*/

#ifndef SIMULATEBUTTONHPP
    #define SIMULATEBUTTONHPP

    #include <vector>
    #include "Tristate.hpp"
    #include "AButton.hpp"
    #include "Variables.hpp"

namespace nts {

    class SimulateButton : public AButton {
        public:
            SimulateButton(std::string, bool &push, Variables &var, sf::Vector2f);

            void func() override;
            void draw(sf::RenderWindow &window) override;

        private:
            sf::Vector2f _size = {100, 50};
            sf::RectangleShape _rec;
            sf::Text _text;
            bool &_push;
    };
}

#endif