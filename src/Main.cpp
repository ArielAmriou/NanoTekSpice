/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Main
*/

#include "NanoTekSpice.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    if (ac != NBARGS)
        return EPIERROR;
    try {
        nts::parsing(av[1]);
    } catch (std::exception &e){
        return EPIERROR;
    }
    return EPISUCCESS;
}