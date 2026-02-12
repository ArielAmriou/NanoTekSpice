/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Pin.hpp"

#define DEBUG(value) std::cout << "\e[0;35m" << "DEBUG: " <<  "\e[0;37m" << "\t" << value << std::endl;

void nts::AComponent::simulate(std::size_t tick) noexcept {};

void nts::AComponent::setLink(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin)
{
    if (pin >= _nbPins || otherPin >= other.getNbPin())
        throw NoSuchPin();
    if (getPinMode(pin) == other.getPinMode(otherPin))
        throw ConnectionException();
    _pins[pin].setConnection(other, otherPin);
    other.getPin(otherPin).setConnection(*this, pin);
};

nts::Mode nts::AComponent::getPinMode(std::size_t pin) {
    if (pin >= this->_nbPins)
        throw NoSuchPin();
    return this->_pins[pin].getMode();
}

nts::Pin &nts::AComponent::getPin(size_t pinNb)
{
    if (pinNb >= _nbPins)
        throw NoSuchPin();
    return _pins[pinNb];
}

nts::Tristate nts::AComponent::compute(std::size_t pin) {
    if (pin >= this->_nbPins)
        throw NoSuchPin();
    return this->computeComponent(pin);
}
