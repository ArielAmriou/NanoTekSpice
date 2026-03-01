/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "CInput.hpp"
#include "COutput.hpp"
#include "CClock.hpp"
#include "CTrue.hpp"
#include "CFalse.hpp"
#include "CAnd.hpp"
#include "CNot.hpp"
#include "COr.hpp"
#include "CXor.hpp"
#include "CLogger.hpp"
#include "C4And.hpp"
#include "C4Nand.hpp"
#include "C4Or.hpp"
#include "C4Xor.hpp"
#include "C4Nor.hpp"
#include "CRom.hpp"

std::unique_ptr<nts::IComponent>
    nts::ComponentFactory::createComponent(const std::string &type, sf::Vector2f pos, sf::Font &font)
{
    if (!componentFactories.contains(type))
        throw UnknownComponentException();
    return componentFactories.at(type)(pos, font, type);
}

const std::map<std::string, nts::ComponentFactory::ComponentCreator>
nts::ComponentFactory::componentFactories = {
    {
        "input", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CInput>(pos, font, type);
        }
    },{
        "output", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::COutput>(pos, font, type);
        }
    },{
        "clock", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CClock>(pos, font, type);
        }
    },{
        "true", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CTrue>(pos, font, type);
        }
    },{
        "false", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CFalse>(pos, font, type);
        }
    },{
        "and", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CAnd>(pos, font, type);
        }
    },{
        "not", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CNot>(pos, font, type);
        }
    },{
        "or", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::COr>(pos, font, type);
        }
    },{
        "xor", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CXor>(pos, font, type);
        }
    },{
        "logger", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CLogger>(pos, font, type);
        }
    },{
        "4081", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::C4And>(pos, font, type);
        }
    },{
        "4071", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::C4Or>(pos, font, type);
        }
    },{
        "4030", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::C4Xor>(pos, font, type);
        }
    },{
        "4001", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::C4Nor>(pos, font, type);
        }
    },{
        "4011", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::C4Nand>(pos, font, type);
        }
    },{
        "rom", [](sf::Vector2f pos, sf::Font &font, const std::string &type){
            return std::make_unique<nts::CRom>(pos, font, type);
        }
    }
};
