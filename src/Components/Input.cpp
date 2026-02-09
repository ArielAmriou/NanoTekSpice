/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input() {
    this->_pins = DEFAULT;
    this->_nbPins = this->_pins.size();
}
