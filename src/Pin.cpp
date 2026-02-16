/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"

void nts::Pin::setConnection(IComponent &component, std::size_t pin)
{
    if (_con.has_value()) {
        Connection con = _con.value();
        con.getComponent().getPin(con.getPin())._con = std::nullopt;
    }
    _con.emplace(Connection(component, pin));
}