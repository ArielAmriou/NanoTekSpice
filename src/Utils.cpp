/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Tristate
*/

#include "Utils.hpp"

nts::Tristate nts::Utils::halfAdder(const nts::Tristate a,
    const nts::Tristate b, nts::Tristate &carry)
{
    carry = a & b;
    return a ^ b;
}

std::unique_ptr<nts::IComponent> &nts::Utils::getComponent(ComponentMap &map, std::string name)
{
    return map.find(name)->second.first;
}