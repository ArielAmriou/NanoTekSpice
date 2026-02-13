/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Tristate
*/

#ifndef TRISTATE_HPP_
#define TRISTATE_HPP_

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false,
    };
}

nts::Tristate operator*(const nts::Tristate a, const nts::Tristate b);
nts::Tristate operator!(const nts::Tristate a);
nts::Tristate operator&(const nts::Tristate a, const nts::Tristate b);
nts::Tristate operator|(const nts::Tristate a, const nts::Tristate b);
nts::Tristate operator^(const nts::Tristate a, const nts::Tristate b);

#endif /* !TRISTATE_HPP_ */
