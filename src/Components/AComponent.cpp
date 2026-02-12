/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Pin.hpp"

void nts::AComponent::setLink(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin) noexcept {};

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
    return this->_pins[pin].getValue();
}

void nts::AComponent::simulate(std::size_t tick) noexcept {
    auto iter = this->_pins.begin();
    auto end = this->_pins.end();

    for (std::size_t i = 0; iter != end; ++i, ++iter) {
        std::optional<nts::Connection> &con = iter.base()->getConnection();
        if (iter.base()->getMode() == nts::Mode::InputMode && con.has_value()){
            con.value().getComponent().simulate(tick);
            if (this->_lastUpdateTick < tick) {
                this->simulateComponent();
                this->_lastUpdateTick = tick;
            }
            auto value =
                con.value().getComponent().compute(con.value().getPin());
            this->_pins[i].setValue(value);
        }
    }
}
