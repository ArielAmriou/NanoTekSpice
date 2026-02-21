/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Utils
*/

#include <algorithm>
#include "Utils.hpp"

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