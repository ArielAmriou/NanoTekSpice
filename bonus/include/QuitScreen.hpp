/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** QuitScreen
*/

#ifndef QUITSCREENHPP
#define QUITSCREENHPP

#include <SFML/Graphics.hpp>
#include <array>
#include "AButton.hpp"
#include "Variables.hpp"
#include "QuitButton.hpp"

namespace nts {

    enum QuitButtonType {
        DONTSAVE,
        SAVE,
        CANCEL,
        NBQUIT,
    };

    class QuitScreen : public AButton {
        public:
            QuitScreen(Variables &var);

            void draw(sf::RenderWindow &window) override;
            void event(sf::Event event, sf::RenderWindow &window);

            void func() override;

        private:
            void initButton();
            Variables &_var;
            sf::Vector2f _size = {600, 300};
            sf::Vector2f _pos = {WINDOW_SIZE_X / 2 - _size.x / 2, WINDOW_SIZE_Y / 2 - _size.y / 2};
            sf::RectangleShape _rec;
            sf::RectangleShape _button;
            sf::Text _buttonText;
            sf::Text _text;
            std::array<bool, NBQUIT> _push;
            std::array<QuitButton, NBQUIT> _buttons;
    };
}

#endif
