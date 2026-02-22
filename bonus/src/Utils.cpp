/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Utils
*/

#include <algorithm>
#include <memory>
#include "Utils.hpp"
#include "Pin.hpp"

std::string nts::Utils::toUpper(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

sf::Color nts::Utils::colorOffset(const sf::Color &color, int offset)
{
    return sf::Color(color.r + offset, color.g + offset, color.b + offset);
}

sf::Color nts::Utils::colorOpacity(const sf::Color &color, int opacity)
{
    return sf::Color(color.r, color.g, color.b, opacity);
}

nts::Tristate nts::Utils::halfAdder(const nts::Tristate a,
    const nts::Tristate b, nts::Tristate &carry)
{
    carry = a & b;
    return a ^ b;
}

nts::Tristate nts::Utils::fullAdder(const nts::Tristate a,
    const nts::Tristate b, nts::Tristate &carry)
{
    auto s = (a ^ b) ^ carry;
    carry = (a & b) | ((a ^ b) & carry);
    return s;
}

std::unique_ptr<nts::IComponent> &nts::Utils::getComponent(ComponentMap &map, std::string name)
{
    return map.find(name)->second.first;
}

void nts::Utils::removeCon(ComponentMap &components, std::string name)
{
    auto component = getComponent(components, name).get();

    for (size_t i = 0; i < component->getNbPin(); i++) {
        auto pin = component->getPin(i);
        if (pin.getMode() == Mode::InputMode || pin.getMode() == Mode::UnusedMode)
            continue;
        for (auto iter = components.begin(); iter != components.end(); iter++) {
            auto &other = Utils::getComponent(components, iter->first);
            if (other.get() == component)
                continue;
            for (size_t i = 0; i < other->getNbPin(); i++) {
                auto &otherPin = other->getPin(i);
                if (otherPin.getConnection().has_value()
                    && std::addressof(otherPin.getConnection().value().getComponent().get()) == component)
                    otherPin.resetCon();
            }
        }
    }
}