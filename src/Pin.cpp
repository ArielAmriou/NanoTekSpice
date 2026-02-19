/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"

void nts::Pin::setConnection(
    std::reference_wrapper<IComponent> component, std::size_t pin)
{
    _con.emplace(Connection(component, pin));
}

nts::Pin &nts::Pin::operator=(const nts::Pin &right) {
    this->_mode = right._mode;
    this->_value = right._value;
    return *this;
};
