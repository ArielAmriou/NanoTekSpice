/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** BasicOperation
*/

#include "BasicOperation.hpp"

nts::Tristate nts::BasicOperation::notOperation(nts::Tristate a) {
    auto result = Undefined;
    if (a == nts::True)
        result = nts::False;
    if (a == nts::False)
        result = nts::True;
    return result;
}

nts::Tristate nts::BasicOperation::andOperation(nts::Tristate a, nts::Tristate b) {
    auto result = True;
    if (a == b)
        result = a;
    else if (a == nts::False || b == nts::False)
        result = nts::False;
    else if (a == nts::Undefined || b == nts::Undefined)
        result = nts::Undefined;
    return result;
}

nts::Tristate nts::BasicOperation::orOperation(nts::Tristate a, nts::Tristate b) {
    return nts::Undefined;
}

nts::Tristate nts::BasicOperation::xorOperation(nts::Tristate a, nts::Tristate b) {
    return nts::Undefined;
}
