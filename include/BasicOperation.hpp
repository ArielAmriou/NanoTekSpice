/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** BasicOperation
*/

#ifndef BASICOPERATION_HPP
    #define BASICOPERATION_HPP

#include "IComponent.hpp"

namespace nts {
    class BasicOperation {
        public:
            static Tristate notOperation(Tristate);
            static Tristate andOperation(Tristate, Tristate);
            static Tristate orOperation(Tristate, Tristate);
            static Tristate xorOperation(Tristate, Tristate);
    };
}

#endif