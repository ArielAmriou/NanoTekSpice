/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** QuitScreen
*/

#include "QuitScreen.hpp"
#include "Utils.hpp"
#include "ComponentButton.hpp"
#include "Save.hpp"

nts::QuitScreen::QuitScreen(Variables &var)
    : AButton(ButtonType::QUIT), _var(var), _rec(_size), _push({false, false, false}),
    _buttons({QuitButton("Don't Save", _push[DONTSAVE], _var, {WINDOW_SIZE_X / 2 - 175, WINDOW_SIZE_Y / 2}),
            QuitButton("Save", _push[SAVE], _var, {WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2}),
            QuitButton("Cancel", _push[CANCEL], _var, {WINDOW_SIZE_X / 2 + 175, WINDOW_SIZE_Y / 2})})
{
    _rec.setPosition(_pos);
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _text.setFont(_var._font);
    _text.setCharacterSize(20);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setFillColor(sf::Color::Black);
    initButton();
}

void nts::QuitScreen::initButton()
{
    sf::FloatRect rc;
    sf::Vector2f pos = {_pos.x + _size.x - BUTTONSIZE - 10, _pos.y + 10};
    _button.setSize({BUTTONSIZE, BUTTONSIZE});
    _button.setPosition(pos);
    _button.setFillColor(DARKGREY);
    _button.setOutlineThickness(2);
    _button.setOutlineColor(sf::Color::Black);
    setBound(_button.getGlobalBounds());
    _buttonText.setFont(_var._font);
    _buttonText.setStyle(sf::Text::Style::Bold);
    _buttonText.setCharacterSize(TEXTSIZE);
    _buttonText.setString(Utils::toUpper("x"));
    rc = _buttonText.getLocalBounds();
    _buttonText.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _buttonText.setPosition({pos.x + BUTTONSIZE / 2, pos.y + BUTTONSIZE / 2});
}

void nts::QuitScreen::draw(sf::RenderWindow &window)
{
    if (!_var._quit)
        return;
    _rec.setFillColor(nts::LIGHTBLUE);
    _rec.setSize(_size);
    window.draw(_rec);
    _rec.setFillColor(nts::GREY);
    _rec.setSize({_size.x, 50});
    window.draw(_rec);
    if (_hover)
        _button.setFillColor(Utils::colorOffset(_button.getFillColor(), -50));
    window.draw(_button);
    window.draw(_buttonText);
    
    sf::FloatRect rc;
    _text.setString("NanoTeckSpice");
    rc = _text.getLocalBounds();
    _text.setOrigin(0, rc.top + rc.height / 2);
    _text.setPosition({_pos.x + 10, _pos.y + 25});
    window.draw(_text);
    _text.setString("Do you whant to save \"" + _var._filename + "\" ?");
    rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _text.setPosition({_pos.x + _size.x / 2, _pos.y + 100});
    window.draw(_text);
    std::string tmp = "Last save : ";
    if (_var._lastSave.asMicroseconds() == 0)
        tmp += "Never.";
    else {
        auto second = _var._clock.getElapsedTime().asSeconds() - _var._lastSave.asSeconds();
        tmp += std::to_string(static_cast<int>(second / 60)) + ":" + std::to_string(static_cast<int>(second) % 60) + ".";
    }
    _text.setString(tmp);
    rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _text.setPosition({_pos.x + _size.x / 2, _pos.y + 130});
    window.draw(_text);
    _button.setFillColor(DARKGREY);
    for (auto &button : _buttons)
        button.draw(window);
}

void nts::QuitScreen::event(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (!_var._quit)
        return;
    click(mousePos, event);
    for (auto &button : _buttons)
        button.click(mousePos, event);
    if (_push[DONTSAVE])
        _var._window.close();
    if (_push[SAVE]) {
        Save::run(_var._components, _var._filename, _var);
        _var._window.close();
    }
    if (_push[CANCEL]) {
        _push[CANCEL] = false;
        _var._quit = false;
    }
    auto tmp = _var._clock.getElapsedTime();
}

void nts::QuitScreen::func()
{
    _var._quit = !_var._quit;
}
