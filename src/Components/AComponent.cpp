/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Pin.hpp"

void nts::AComponent::simulate(std::size_t tick) noexcept {};

void nts::AComponent::setLink(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin) noexcept {};

nts::Mode nts::AComponent::getPinMode(std::size_t pin) {
    if (pin >= this->_nbPins)
        throw NoSuchPin();
    return this->_pins[pin].getMode();
}

nts::Pin nts::AComponent::getPin(size_t pinNb)
{
    if (pinNb >= _nbPins)
        throw NoSuchPin();
    return _pins[pinNb];
}