/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** ChangeState
*/

#ifndef CHANGESTATEHPP
    #define CHANGESTATEHPP

    #include <array>
    #include "TristateButton.hpp"
    #include "AButton.hpp"
    #include "Variables.hpp"

namespace nts {
    class ChangeState {
        public:
            ChangeState(Variables &var);

            void draw(sf::RenderWindow &window);
            void event(sf::Event event, sf::RenderWindow &window);
            void updateValue(std::string);
            void updateState();

            void setShow(bool show) {_show = show;}
            bool getShow() {return _show;}
            void resetComponent() {_component = std::nullopt;}

        private:
            Tristate _state;
            std::array<bool, 3> _push;
            std::array<TristateButton, 3> _buttons;
            bool _show = false;
            std::optional<std::string> _component = std::nullopt;
            Variables _var;
    };
}

#endif