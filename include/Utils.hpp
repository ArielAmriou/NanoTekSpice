/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "Tristate.hpp"

namespace nts {
    class Utils {
        public:
            static Tristate halfAdder(const Tristate a,
                const Tristate b, Tristate &carry);
    };
}

#endif /* !UTILS_HPP_ */
