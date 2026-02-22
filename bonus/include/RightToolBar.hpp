/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** RightToolBar
*/

#ifndef RIGHTTOOLBARHPP
    #define RIGHTTOOLBARHPP

    #include <memory>
    #include <SFML/Graphics.hpp>
    #include "ComponentButton.hpp"
    #include "Slider.hpp"
    #include "AButton.hpp"

    constexpr float WIDTH = 150;
    constexpr float SLIDERWIDTH = 10;
    constexpr float MINGAP = 75;
    constexpr float BUTTONY = 15;
    constexpr float BUTTONSIZE = 30;
    constexpr int HOVEROFFSET = 25;

namespace nts {

    class RightToolBar : public AButton {
        public:
            RightToolBar(sf::Vector2u windowSize, ComponentMap &components, sf::Font &font, sf::RenderWindow &window);
            ~RightToolBar() {};

            void draw(sf::RenderWindow &window) override;
            void event(sf::Event event, sf::RenderWindow &window);

            void func() override;

        private:
            void initAddButton(ComponentMap &components, sf::Font &font, sf::RenderWindow &window, unsigned int posx);
            void initButton(const sf::Font &font, unsigned int posx);
            sf::Vector2f _size;
            sf::RectangleShape _rec;
            sf::RectangleShape _button;
            sf::Text _buttonText;
            Slider _slider;
            std::vector<std::unique_ptr<ComponentButton>> _buttons;
            bool _open = true;
    };
}

#endif