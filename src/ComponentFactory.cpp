/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

#include "CInput.hpp"
#include "COutput.hpp"
#include "CTrue.hpp"
#include "CFalse.hpp"
#include "CClock.hpp"
#include "CNot.hpp"

std::unique_ptr<nts::IComponent>
    nts::ComponentFactory::createComponent(const std::string &type)
{
    if (!componentFactories.contains(type))
        throw UnknownComponentException();
    return componentFactories.at(type)();
}

const std::unordered_map<std::string, nts::ComponentFactory::componentCreator>
nts::ComponentFactory::componentFactories = {
    {
        "input", []{
            return std::make_unique<nts::CInput>();
        }
    },{
        "output", []{
            return std::make_unique<nts::COutput>();
        }
    },{
        "true", []{
            return std::make_unique<nts::CTrue>();
        }
    },{
        "false", []{
            return std::make_unique<nts::CFalse>();
        }
    },{
        "clock", []{
            return std::make_unique<nts::CClock>();
        }
    },{
        "not", []{
            return std::make_unique<nts::CNot>();
        }
    }
};
