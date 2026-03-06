/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** QuitButton
*/

#ifndef QUITBUTTONHPP
    #define QUITBUTTONHPP

    #include <vector>
    #include "Tristate.hpp"
    #include "AButton.hpp"
    #include "Variables.hpp"

namespace nts {

    class QuitButton : public AButton {
        public:
            QuitButton(std::string, bool &push, Variables &var, sf::Vector2f);

            void func() override;
            void draw(sf::RenderWindow &window) override;

            void changeName(std::string);

        private:
            sf::Vector2f _size = {125, 50};
            sf::RectangleShape _rec;
            sf::Text _text;
            bool &_push;
    };
}

#endif