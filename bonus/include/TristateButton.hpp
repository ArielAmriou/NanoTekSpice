/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** TristateButton
*/

#ifndef TRISTATEBUTTONHPP
    #define TRISTATEBUTTONHPP

    #include <vector>
    #include "Tristate.hpp"
    #include "AButton.hpp"
    #include "Variables.hpp"

namespace nts {

    static const std::vector<std::string> TRISTATENAME = {
        "undefine",
        "false",
        "true"
    };

    static const std::vector<sf::Color> TRISTATECOLOR = {
        GREY,
        sf::Color::Red,
        sf::Color::Green,
    };

    class TristateButton : public AButton {
        public:
            TristateButton(Tristate state, bool &push, Variables &var);

            void func() override;
            void draw(sf::RenderWindow &window) override;
            void changePos(sf::Vector2f newPos);

        private:
            sf::Vector2f _size = {80, 25};
            sf::RectangleShape _rec;
            sf::Text _text;
            Tristate _state;
            bool &_push;
            sf::Color _color;
    };
}

#endif