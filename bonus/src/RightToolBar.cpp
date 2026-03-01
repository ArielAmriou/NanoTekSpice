/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** RightToolBar
*/

#include "RightToolBar.hpp"
#include "Utils.hpp"
#include "ComponentButton.hpp"
#include "ComponentFactory.hpp"

nts::RightToolBar::RightToolBar(Variables &var)
    : AButton(ButtonType::DRAWER), _variables(var), _size({WIDTH, static_cast<float>(var._size.y)}),
    _rec(_size), _slider({var._size.x - SLIDERWIDTH, 0}, {SLIDERWIDTH, _size.y}, sf::Color::White)
{
    _rec.setPosition({var._size.x - WIDTH, 0});
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setOutlineThickness(3);
    _rec.setFillColor(LIGHTBLUE);
    _slider.setSrollZone(_rec.getGlobalBounds());
    initAddButton(var._size.x);
    initButton(var._size.x - WIDTH);
}

void nts::RightToolBar::initAddButton(unsigned int posx)
{
    float yGap = _size.y / (ComponentFactory::componentFactories.size());
    if (yGap < MINGAP)
        yGap = MINGAP;
    float yoffset = yGap / 2;
    float maxScroll = 0;
    auto iter = ComponentFactory::componentFactories.begin();
    for (std::size_t i= 0; i < ComponentFactory::componentFactories.size(); i++) {
        _buttons.push_back(std::make_unique<ComponentButton>(sf::Vector2f{static_cast<float>(posx - 125), yGap * i + yoffset}, iter->first, _variables));
        maxScroll += yGap;
        iter++;
    }
    maxScroll -= _size.y;
    _slider.setMaxScroll(maxScroll);
}

void nts::RightToolBar::initButton(unsigned int posx)
{
    sf::FloatRect rc;
    _button.setSize({BUTTONSIZE, BUTTONSIZE});
    _buttonPos = {posx - BUTTONSIZE, BUTTONY};
    _button.setPosition(_buttonPos);
    _button.setFillColor(DARKGREY);
    _button.setOutlineThickness(2);
    _button.setOutlineColor(sf::Color::Black);
    setBound(_button.getGlobalBounds());
    _buttonText.setFont(_variables._font);
    _buttonText.setStyle(sf::Text::Style::Bold);
    _buttonText.setCharacterSize(TEXTSIZE);
    _buttonText.setString(Utils::toUpper(">"));
    rc = _buttonText.getLocalBounds();
    _buttonText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _buttonText.setPosition({_buttonPos.x + BUTTONSIZE / 2, _buttonPos.y + BUTTONSIZE / 2});
}

void nts::RightToolBar::draw(sf::RenderWindow &window)
{
    sf::Vector2f pos = _buttonPos;
    if (_variables._rightToolBar) {
        _buttonText.setString(Utils::toUpper("<"));
    } else {
        pos.x += WIDTH;
        _buttonText.setString(Utils::toUpper(">"));
    }
    _button.setPosition(pos);
    setBound(_button.getGlobalBounds());
    _buttonText.setPosition(pos.x + BUTTONSIZE / 2, pos.y + BUTTONSIZE / 2);
    if (_hover)
        _button.setFillColor(Utils::colorOffset(_button.getFillColor(), -HOVEROFFSET));
    window.draw(_button);
    _button.setFillColor(DARKGREY);
    window.draw(_buttonText);
    if (_variables._rightToolBar) {
        window.draw(_rec);
        for (auto &button : _buttons)
            button->draw(window);
        _slider.draw(window);
    }
}

void nts::RightToolBar::event(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
        _variables._rightToolBar = !_variables._rightToolBar;

    click(mousePos, event);
    if (!_variables._rightToolBar)
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
    _variables._rightToolBar = !_variables._rightToolBar;
}