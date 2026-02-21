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