/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** APartComponent
*/

#include "APartComponent.hpp"

nts::APartComponent::APartComponent(const std::string &name, sf::Vector2f pos, sf::Vector2f size,
    sf::Font &font, std::vector<std::tuple<Mode, sf::Vector2f, std::string, Tristate>> pins, std::size_t nbPart,
    std::size_t inputsPerPart,std::size_t outputsPerPart)
    : AComponent(name, pos, size, font, pins), _nbPart(nbPart), _inputsPerPart(inputsPerPart),
    _outputsPerPart(outputsPerPart), _partsLastComputedTick(nbPart, 0)
{}

void nts::APartComponent::simulate(std::size_t tick) noexcept
{
    if (this->_lastUpdateTick == tick)
        return;
    this->_lastUpdateTick = tick;
    for (std::size_t i = 0; i < _nbPart; i++)
        simulatePart(i, tick);
}

void nts::APartComponent::simulateIntern(std::size_t id, std::size_t tick)
{
    auto &con = this->_pins[id].getConnection();
    if (!con.has_value()) {
        if (this->_pins[id].getMode() == nts::Mode::InputMode
            || this->_pins[id].getMode() == nts::Mode::DualMode)
            this->_pins[id].setValue(Undefined);
        return;
    }
    auto &component = con.value().getComponent().get();
    std::size_t pin = con.value().getPin();
    if (&component != this)
        component.simulate(tick);
    else
        simulatePart(findOutputPart(pin), tick);
    this->_pins[id].setValue(component.compute(pin));
}

void nts::APartComponent::simulatePart(std::size_t id, std::size_t tick)
{
    if (_partsLastComputedTick[id] == tick)
        return;
    _partsLastComputedTick[id] = tick;
    auto &inputs = getInputPins();
    std::size_t inputBase = id * _inputsPerPart;
    for (std::size_t i = 0; i < _inputsPerPart; i++)
        simulateIntern(inputs[inputBase + i], tick);
    computePart(id);
}

std::size_t nts::APartComponent::findOutputPart(std::size_t outputPin)
{
    std::size_t value = 0;
    auto &outputs = getOutputPins();
    for (std::size_t i = 0; i < outputs.size(); i++) {
        if (outputs[i] == outputPin) {
            value = i / _outputsPerPart;
            break;
        }
    }
    return value;
}