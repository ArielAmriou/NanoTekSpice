/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Tristate
*/

#include "Tristate.hpp"

// * (nand)
nts::Tristate operator*(const nts::Tristate a, const nts::Tristate b)
{
    auto result = nts::True;
    if (a == nts::Undefined || b == nts::Undefined)
        result = nts::Undefined;
    else if (a == b && a == nts::True)
        result = nts::False;
    return result;
}

// ! (not)
nts::Tristate operator!(const nts::Tristate a)
{
    return a * a;
}

// & (and)
nts::Tristate operator&(const nts::Tristate a, const nts::Tristate b) {
    return !(a * b);
}

// | (or)
nts::Tristate operator|(const nts::Tristate a, const nts::Tristate b)
{
    if (a == nts::True || b == nts::True)
        return nts::True;
    return !a * !b;
}

// ^ (xor)
nts::Tristate operator^(const nts::Tristate a, const nts::Tristate b)
{
    auto tmp = a * b;
    return (tmp * a) * (tmp * b);
}
