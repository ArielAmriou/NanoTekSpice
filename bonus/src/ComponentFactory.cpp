/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "CInput.hpp"
#include "COutput.hpp"

std::unique_ptr<nts::IComponent>
    nts::ComponentFactory::createComponent(const std::string &type, sf::Vector2f pos, sf::Font &font)
{
    if (!componentFactories.contains(type))
        throw UnknownComponentException();
    return componentFactories.at(type)(pos, font, type);
}

const std::unordered_map<std::string, nts::ComponentFactory::ComponentCreator>
nts::ComponentFactory::componentFactories = {
    {
        "input", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CInput>(pos, font, type);
        }
    },{
        "output", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::COutput>(pos, font, type);
        }
    }
};
