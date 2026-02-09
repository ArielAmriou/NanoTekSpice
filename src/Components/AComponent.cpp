/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::simulate(std::size_t tick) noexcept {};

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept {};

nts::Mode nts::AComponent::getPinMode(std::size_t pin) {
    if (pin >= this->_nbPins)
        throw NoSuchPin();
    auto a = this->_pins[pin].second;
    return a;
}
