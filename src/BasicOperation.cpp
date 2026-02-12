/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** BasicOperation
*/

#include "BasicOperation.hpp"

nts::Tristate nts::BasicOperation::notOperation(nts::Tristate a) {
    if (a == nts::True)
        return nts::False;
    if (a == nts::False)
        return nts::True;
    return nts::Undefined;
}

nts::Tristate nts::BasicOperation::andOperation(nts::Tristate a, nts::Tristate b) {

}

nts::Tristate nts::BasicOperation::orOperation(nts::Tristate a, nts::Tristate b) {

}

nts::Tristate nts::BasicOperation::xorOperation(nts::Tristate a, nts::Tristate b) {

}
