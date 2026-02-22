/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Pin.hpp"
#include "Utils.hpp"

nts::AComponent::AComponent(const std::string &name, sf::Vector2f pos, sf::Vector2f size, sf::Font &font)
    : _size(size), _rec(size), _pos(pos), _name(name)
{
    sf::FloatRect rc;
    _rec.setFillColor(GREY);
    _rec.setOutlineThickness(3);
    _rec.setOutlineColor(sf::Color::Black);
    _text.setFont(font);
    _text.setCharacterSize(20);
    _text.setStyle(sf::Text::Bold);
    if (_name == "input")
        _text.setString("IN");
    else if (_name == "output")
        _text.setString("OUT");
    else
        _text.setString(Utils::toUpper(name));

    rc = _text.getLocalBounds();
    _text.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _text.rotate(-90);
    _text.setFillColor(sf::Color::Black);
};

void nts::AComponent::setLink(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin)
{
    if (pin >= _nbPins)
        throw NoSuchPin();
    Mode first = getPin(pin).getMode();
    Mode second = other.getPin(otherPin).getMode();
    if (first == second
        || first == Mode::UnusedMode
        || second == Mode::UnusedMode)
        throw ConnectionException();
    try {
        if (first == Mode::InputMode
            || (first == Mode::DualMode && second == Mode::OutputMode))
            _pins[pin].setConnection(other, otherPin);
        else
            other.getPin(otherPin).setConnection(*this, pin);
    } catch (NoSuchPin &e) {
        throw e;
    }
};

nts::Pin &nts::AComponent::getPin(size_t pinNb)
{
    if (pinNb >= _nbPins)
        throw NoSuchPin();
    return _pins[pinNb];
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (pin >= this->_nbPins)
        throw NoSuchPin();
    return this->_pins[pin].getValue();
}

void nts::AComponent::simulate(std::size_t tick) noexcept
{
    auto iter = this->_pins.begin();
    auto end = this->_pins.end();

    if (this->_lastUpdateTick < tick)
        this->_lastUpdateTick = tick;
    else
        return;
    for (std::size_t i = 0; iter != end; ++i) {
        std::optional<nts::Connection> &con = iter.base()->getConnection();
        if ((iter.base()->getMode() == nts::Mode::InputMode
            || iter.base()->getMode() == nts::Mode::DualMode)
            && con.has_value()){
            con.value().getComponent().get().simulate(tick);
            auto value =
                con.value().getComponent().get().compute(con.value().getPin());
            this->_pins[i].setValue(value);
        }
        ++iter;
    }
    this->simulateComponent();
}

void nts::AComponent::resetOutputs(const nts::Tristate value)
{
    for (std::size_t i = 0; i < this->_nbPins; ++i)
        if (this->_pins[i].getMode() == nts::Mode::OutputMode)
            this->_pins[i].setValue(value);
}

void nts::AComponent::draw(sf::RenderWindow &window)
{
    _rec.setPosition(_pos);
    window.draw(_rec);
    _rec.setFillColor(GREY);
    _text.setPosition({_pos.x + _size.x / 2, _pos.y + _size.y / 2});
    window.draw(_text);
}

void nts::AComponent::drawPin(sf::RenderWindow &window)
{
    for (auto &pin : _pins) {
        pin.draw(window, _pos);
    }
}