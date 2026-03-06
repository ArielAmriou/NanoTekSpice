/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <memory>
#include <map>
#include <functional>
#include "IComponent.hpp"

namespace nts {
    class ComponentFactory {
        public:
            using ComponentCreator =
                std::function<std::unique_ptr<nts::IComponent>(sf::Vector2f pos, sf::Font &font, const std::string &type)>;
            static std::unique_ptr<nts::IComponent>
                createComponent(const std::string &type, sf::Vector2f pos, sf::Font &font);
            static const std::map<std::string, ComponentCreator>
                componentFactories;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
