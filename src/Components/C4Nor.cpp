/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** C4Nor
*/

#include "C4Nor.hpp"

nts::C4Nor::C4Nor() : AGateComponent(function)
{}

const nts::Tristate nts::C4Nor::function(Tristate a, Tristate b)
{
    return !(a | b);
}