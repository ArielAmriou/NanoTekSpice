/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Save
*/

#include <fstream>
#include "Save.hpp"
#include "ComponentFactory.hpp"
#include "Pin.hpp"

std::vector<std::size_t> nts::Save::initCounter(ComponentMap &components)
{
    std::vector<std::size_t> counter;

    for (auto iter = ComponentFactory::componentFactories.begin();
        iter != ComponentFactory::componentFactories.end(); iter++) {
            counter.push_back(0);
    }
    return counter;
}

std::size_t nts::Save::findId(std::string type, std::vector<std::size_t> counter)
{
    size_t i = 0;

    for (auto iter = ComponentFactory::componentFactories.begin();
        iter != ComponentFactory::componentFactories.end(); iter++) {
        if (iter->first == type)
            return counter[i]++;
        i++;
    }
    return 0;
}

std::string nts::Save::findLinkName(ComponentMap &components, std::vector<std::size_t> id, std::reference_wrapper<IComponent> component)
{
    size_t i = 0;

    for (auto iter = components.begin(); iter != components.end(); iter++) {
        if (std::addressof(component.get()) == iter->second.first.get())
            return iter->second.second + std::to_string(id[i]);
        i++;
    }
    return "";
}

void nts::Save::run(ComponentMap &components, std::string name)
{
    auto iter = ComponentFactory::componentFactories.begin();
    std::vector<std::size_t> counter = initCounter(components);
    std::vector<std::size_t> id;
    std::ofstream file("save/" + name);
    std::size_t i = 0;
    
    if (!file.is_open())
        return;
    file << ".chipsets:\n";
    for (auto iter = components.begin(); iter != components.end(); iter++) {
        id.push_back(findId(iter->second.second, counter));
        file << iter->second.second << " " << iter->second.second
            << id[i] << " "
            << iter->second.first->getPos().x << " "
            << iter->second.first->getPos().y << "\n";
        i++;
    }
    file << ".links:\n";
    i = 0;
    for (auto iter = components.begin(); iter != components.end(); iter++) {
        auto &component = iter->second.first;
        for (std::size_t j = 0; j < component->getNbPin(); j++) {
            if (!component->getNPin(j).getConnection().has_value())
                continue;
            file << iter->second.second << id[i] << ":" << j + 1 << " "
            << findLinkName(components, id, component->getNPin(j).getConnection().value().getComponent()) << ":"
            << component->getNPin(j).getConnection().value().getPin() + 1 << "\n";
        }
        i++;
    }
}
