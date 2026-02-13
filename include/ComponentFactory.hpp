/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <memory>
#include <unordered_map>
#include <functional>
#include "IComponent.hpp"

namespace nts {
    class ComponentFactory {
        public:
            typedef std::function<std::unique_ptr<nts::IComponent>()>
                componentCreator;
            static std::unique_ptr<nts::IComponent>
                createComponent(const std::string &type);
        private:
            static const std::unordered_map<std::string, componentCreator>
                componentFactories;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
