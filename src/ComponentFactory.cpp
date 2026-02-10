/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

#include "Input.hpp"

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type)
{
    if (!componentFactories.contains(type))
        throw UnknownComponentException();
    return componentFactories.at(type)();
}

const std::unordered_map<std::string, nts::ComponentFactory::componentCreator>
nts::ComponentFactory::componentFactories = {
    {
        "input", []{
            return std::make_unique<nts::Input>();
        }
    }
};
