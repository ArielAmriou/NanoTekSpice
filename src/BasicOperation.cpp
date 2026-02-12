/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** BasicOperation
*/

#include "BasicOperation.hpp"

nts::Tristate nts::BasicOperation::nandOperation(
    nts::Tristate a, nts::Tristate b)
{
    auto result = nts::True;
    if ((a == nts::Undefined && (a == b || b == nts::True))
        || (b == nts::Undefined && a == nts::True))
        result = nts::Undefined;
    else if (a == b && a == nts::True)
        result = nts::False;
    return result;
}

nts::Tristate nts::BasicOperation::notOperation(nts::Tristate a)
{
    return nandOperation(a, a);
}

nts::Tristate nts::BasicOperation::andOperation(
    nts::Tristate a, nts::Tristate b)
{
    return notOperation(nandOperation(a, b));
}

nts::Tristate nts::BasicOperation::orOperation(
    nts::Tristate a, nts::Tristate b)
{
    return nandOperation(notOperation(a), notOperation(b));
}

nts::Tristate nts::BasicOperation::xorOperation(
    nts::Tristate a, nts::Tristate b)
{
    auto tmp = nandOperation(a, b);
    return nandOperation(nandOperation(tmp, a), nandOperation(tmp, b));
}
