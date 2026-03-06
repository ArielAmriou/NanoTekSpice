/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CTrue
*/

#include "CTrue.hpp"

nts::CTrue::CTrue(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CTRUEX, CTRUEY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}
void nts::CTrue::simulateComponent() {};

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CTrue::_defaultPins = {
    {nts::Mode::OutputMode, {CTRUEX - SIDEOFFSET, CTRUEY / 2}, "q", nts::True}
};
