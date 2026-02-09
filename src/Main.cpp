/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Main
*/

#include "Input.hpp"
#include <memory>
#include "ComponentFactory.hpp"

#include "NanoTekSpice.hpp"
#include "Parsing.hpp"

int main(int ac, char **av)
{
    //std::unique_ptr<nts::IComponent> a = nts::ComponentFactory::createComponent("input");
    //a->getPinMode(0);
    if (ac != NBARGS)
        return EPIERROR;
    try {
        nts::parsing(av[1]);
    } catch (std::exception &e){
        return EPIERROR;
    }
    return EPISUCCESS;
}