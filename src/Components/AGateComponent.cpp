/*
** EPITECH PROJECT, 2026
** main
** File description:
** AGateComponent
*/

#include "AGateComponent.hpp"

nts::AGateComponent::AGateComponent(std::function<Tristate(Tristate, Tristate)> func)
    : APartComponent(GATECOMPONENTNBPART, GATECOMPONENTNBIN,
        GATECOMPONENTNBOUT), _func(func)
{
    this->_pins = this->_defaultPins;
    this->_nbPins = this->_pins.size();
}

const std::vector<nts::Pin> nts::AGateComponent::_defaultPins = {
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::OutputMode,
    nts::Mode::OutputMode,
    nts::Mode::InputMode,
    nts::Mode::InputMode,
    nts::Mode::UnusedMode,
};

void nts::AGateComponent::computePart(std::size_t id)
{
    this->_pins[_outputs[id]].setValue(_func(
        this->_pins[_inputs[id * 2]].getValue(),
        this->_pins[_inputs[id * 2 + 1]].getValue()
    ));
}

const std::vector<std::size_t> nts::AGateComponent::_inputs = {
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8
};

const std::vector<std::size_t> nts::AGateComponent::_outputs = {
    Q1,
    Q2,
    Q3,
    Q4,
};