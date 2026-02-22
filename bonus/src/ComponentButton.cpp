/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** ComponentButton
*/

#include "ComponentButton.hpp"
#include "ComponentFactory.hpp"

nts::ComponentButton::ComponentButton(
    sf::Vector2f pos, std::string name, ComponentMap &components, sf::Font &font, sf::RenderWindow &window)
    : AButton(ButtonType::COMPONENT), _rec(_size), _name(name), _components(components), _font(font), _window(window)
{
    _rec.setFillColor(GREY);
    _rec.setOutlineThickness(OUTLINE);
    _rec.setOutlineColor(sf::Color::Black);
    _rec.setOrigin(0, _size.y / 2);
    _rec.setPosition(pos);
    setBound(_rec.getGlobalBounds());

    _text.setFont(_font);
    _text.setStyle(sf::Text::Style::Bold);
    _text.setCharacterSize(TEXTSIZE);
    _text.setString(Utils::toUpper(name));

    sf::FloatRect rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _text.setPosition(pos.x + _size.x / 2, pos.y);
};

void nts::ComponentButton::draw(sf::RenderWindow &window)
{
    if (_hover) {
        _rec.setFillColor(Utils::colorOffset(_rec.getFillColor(), -50));
    }
    window.draw(_rec);
    window.draw(_text);
    _rec.setFillColor(GREY);
}

void nts::ComponentButton::changePos(sf::Vector2f offset)
{
    _rec.setPosition(_rec.getPosition() + offset);
    _text.setPosition(_text.getPosition() + offset);
    setBound(_rec.getGlobalBounds());
}

void nts::ComponentButton::func()
{
    static std::size_t id = 0;
    sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
    _components.emplace(std::to_string(id),
        std::make_pair(ComponentFactory::createComponent(_name, mousePos, _font), _name));
    id++;
}