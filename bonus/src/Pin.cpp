/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"
#include "Utils.hpp"

nts::Pin::Pin(nts::Mode mode, nts::Tristate value, sf::Vector2f pos, sf::Font &font, std::string name):
    _mode(mode), _value(value), _con(), _pos(pos), _circle(5), _rec(_size)
{
    _circle.setOrigin(5, 5);
    _rec.setFillColor(DARKGREY);
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setOrigin({_size.x / 2, _size.y});
    _text.setFont(font);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setCharacterSize(15);
    _text.setString(Utils::toUpper(name));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
};

nts::Pin::Pin(nts::Mode mode, sf::Vector2f pos, sf::Font &font, std::string name):
    _mode(mode), _value(Undefined), _con(), _pos(pos), _circle(5), _rec(_size)
{
    _circle.setOrigin(5, 5);
    _rec.setFillColor(DARKGREY);
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setOrigin({_size.x / 2, _size.y});
    _text.setFont(font);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setCharacterSize(15);
    _text.setString(Utils::toUpper(name));
    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
};

void nts::Pin::setConnection(
    std::reference_wrapper<IComponent> component, std::size_t pin)
{
    _con.emplace(Connection(component, pin));
}

nts::Pin &nts::Pin::operator=(const nts::Pin &right) {
    this->_mode = right._mode;
    this->_value = right._value;
    this->_circle = right._circle;
    this->_pos = right._pos;
    return *this;
};

void nts::Pin::draw(sf::RenderWindow &window, sf::Vector2f pos)
{
    sf::Color color(sf::Color::Black);
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (_value == False)
        color = nts::RED;
    if (_value == True)
        color = nts::GREEN;
    pos += _pos;
    _circle.setPosition(pos);
    _rec.setPosition({pos.x, pos.y - 10});
    _text.setPosition({pos.x, pos.y - 10 - _size.y / 2});
    _circle.setFillColor(color);
    window.draw(_circle);
}

void nts::Pin::drawConnection(sf::RenderWindow &window, sf::Vector2f pos)
{
    if (_con.has_value())
        _con.value().draw(window, pos + _pos);
}

void nts::Pin::drawLabel(sf::RenderWindow &window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (getPin().getGlobalBounds().contains(mousePos)) {
        window.draw(_rec);
        window.draw(_text);
    }
}
