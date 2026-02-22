/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** ComponentButton
*/


#ifndef ComponentBUTTONHPP
    #define ComponentBUTTONHPP

    #include <string>
    #include "AButton.hpp"
    #include "Utils.hpp"

namespace nts {

    constexpr int TEXTSIZE = 20;
    constexpr int OUTLINE = 2;

    class ComponentButton : public AButton {
        public:
            ComponentButton(sf::Vector2f pos, std::string name, const sf::Font &font);

            void func() override {DEBUG(_name);}

            void draw(sf::RenderWindow &window) override;

            void changePos(sf::Vector2f offset);

        private:
            sf::Vector2f _size = {100, 50};
            sf::RectangleShape _rec;
            sf::Text _text;
            std::string _name;
    };
}

#endif