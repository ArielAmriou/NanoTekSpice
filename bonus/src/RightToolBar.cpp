/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** RightToolBar
*/

#include "RightToolBar.hpp"
#include "Utils.hpp"
#include "ComponentButton.hpp"

nts::RightToolBar::RightToolBar(sf::Vector2u windowSize, const sf::Font &font) : AButton(ButtonType::DRAWER), _size({WIDTH, static_cast<float>(windowSize.y)}), _rec(_size), _slider({windowSize.x - SLIDERWIDTH, 0}, {SLIDERWIDTH, _size.y}, sf::Color::White)
{
    _rec.setPosition({windowSize.x - WIDTH, 0});
    _rec.setFillColor(DARKGREY);
    _slider.setSrollZone(_rec.getGlobalBounds());
    initAddButton(font, windowSize.x);
    initButton(font, windowSize.x - WIDTH);
}

void nts::RightToolBar::initAddButton(const sf::Font &font, unsigned int posx)
{
    float yGap = _size.y / (ChipsetsName.size());
    if (yGap < MINGAP)
        yGap = MINGAP;
    float yoffset = yGap / 2;
    float maxScroll = 0;
    for (std::size_t i= 0; i < ChipsetsName.size(); i++) {
        _buttons.push_back(std::make_unique<ComponentButton>(sf::Vector2f{static_cast<float>(posx - 125), yGap * i + yoffset}, ChipsetsName[i], font));
        maxScroll += yGap;
    }
    maxScroll -= _size.y;
    _slider.setMaxScroll(maxScroll);
}

void nts::RightToolBar::initButton(const sf::Font &font, unsigned int posx)
{
    sf::FloatRect rc;
    _button.setSize({BUTTONSIZE, BUTTONSIZE});
    _button.setPosition({posx - BUTTONSIZE, BUTTONY});
    _button.setFillColor(DARKGREY);
    _button.setOutlineThickness(2);
    _button.setOutlineColor(sf::Color::Black);
    setBound(_button.getGlobalBounds());
    _buttonText.setFont(font);
    _buttonText.setStyle(sf::Text::Style::Bold);
    _buttonText.setCharacterSize(TEXTSIZE);
    _buttonText.setString(Utils::toUpper(">"));
    rc = _buttonText.getLocalBounds();
    _buttonText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _buttonText.setPosition(posx - BUTTONSIZE + BUTTONSIZE / 2, BUTTONY + BUTTONSIZE / 2);
}

void nts::RightToolBar::draw(sf::RenderWindow &window)
{
    if (_hover)
        _button.setFillColor(Utils::colorOffset(_button.getFillColor(), -HOVEROFFSET));
    window.draw(_button);
    _button.setFillColor(DARKGREY);
    window.draw(_buttonText);
    if (_open) {
        window.draw(_rec);
        for (auto &button : _buttons)
            button->draw(window);
        _slider.draw(window);
    }
}

void nts::RightToolBar::event(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    click(mousePos, event);
    if (!_open)
        return;

    for (auto &button : _buttons) {
        button->click(mousePos, event);
    }

    float before = _slider.getScroll();
    float update = _slider.event(event, window);

    if (before != update)
        for (auto &button : _buttons) {
            button->changePos({0, before - update});
        }
}

void nts::RightToolBar::func()
{
    _open = !_open;
    sf::Vector2f pos = _button.getPosition();
    if (_open) {
        pos.x -= WIDTH;
        _buttonText.setString(Utils::toUpper(">"));
    } else {
        pos.x += WIDTH;
        _buttonText.setString(Utils::toUpper("<"));
    }
    _button.setPosition(pos);
    setBound(_button.getGlobalBounds());
    _buttonText.setPosition(pos.x + BUTTONSIZE / 2, pos.y + BUTTONSIZE / 2);
}