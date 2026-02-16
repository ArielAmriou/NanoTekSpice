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
#include "CAnd.hpp"
#include "CXor.hpp"
#include "COr.hpp"
#include "C6Not.hpp"
#include "C4And.hpp"
#include "C4Or.hpp"
#include "C4Xor.hpp"
#include "C4Nor.hpp"
#include "C4Nand.hpp"
#include "CAdder.hpp"
#include "CLogger.hpp"
#include "CSelector.hpp"
#include "CDecoder.hpp"

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
    },{
        "and", []{
            return std::make_unique<nts::CAnd>();
        }
    },{
        "4069", []{
            return std::make_unique<nts::C6Not>();
        }
    },{
        "or", []{
            return std::make_unique<nts::COr>();
        }
    },{
        "xor", []{
            return std::make_unique<nts::CXor>();
        }
    },{
        "4081", []{
            return std::make_unique<nts::C4And>();
        }
    },{
        "4071", []{
            return std::make_unique<nts::C4Or>();
        }
    },{
        "4030", []{
            return std::make_unique<nts::C4Xor>();
        }
    },{
        "4001", []{
            return std::make_unique<nts::C4Nor>();
        }
    },{
        "4011", []{
            return std::make_unique<nts::C4Nand>();
        }
    },{
        "4008", []{
            return std::make_unique<nts::CAdder>();
        }
    },{
        "logger", []{
            return std::make_unique<nts::CLogger>();
        }
    },{
        "4512", []{
            return std::make_unique<nts::CSelector>();
        }
    },{
        "4514", []{
            return std::make_unique<nts::CDecoder>();
        }
    }
};
