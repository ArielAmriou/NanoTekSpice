/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CKeyboard
*/

#include "CKeyboard.hpp"

nts::CKeyboard::CKeyboard(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CKEYBOARDX, CKEYBOARDY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
}

void nts::CKeyboard::setPins()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
        this->_pins[9].setValue(nts::Tristate::False);
        return;
    }
    for (size_t i = 0; i < _inputs.size(); ++i) {
        if (sf::Keyboard::isKeyPressed(std::get<0>(_inputs[i]))) {
            char c = std::get<1>(_inputs[i]);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                c = std::get<2>(_inputs[i]);
            this->_pins[1].setValue((nts::Tristate)((bool)(c & 1)));
            this->_pins[2].setValue((nts::Tristate)((bool)(c & 2)));
            this->_pins[3].setValue((nts::Tristate)((bool)(c & 4)));
            this->_pins[4].setValue((nts::Tristate)((bool)(c & 8)));
            this->_pins[5].setValue((nts::Tristate)((bool)(c & 16)));
            this->_pins[6].setValue((nts::Tristate)((bool)(c & 32)));
            this->_pins[7].setValue((nts::Tristate)((bool)(c & 64)));
            this->_pins[8].setValue((nts::Tristate)((bool)(c & 128)));
            this->_pins[9].setValue(nts::Tristate::True);
            return;
        }
    }
    this->_pins[9].setValue(nts::Tristate::False);
}

void nts::CKeyboard::simulateComponent() {
    if (this->_pins[0].getValue() != nts::Tristate::False)
        this->resetOutputs(!this->_pins[0].getValue());
    setPins();
};

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CKeyboard::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CKEYBOARDY / 2}, "CTR", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 1}, "O0", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 2}, "O1", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 3}, "O2", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 4}, "O3", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 5}, "O4", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 6}, "O5", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 7}, "O6", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 8}, "O7", nts::Undefined},
    {nts::Mode::OutputMode, {CKEYBOARDX - SIDEOFFSET, CKEYBOARDY / 10 * 9}, "C", nts::Undefined}
};

const std::vector<std::tuple<sf::Keyboard::Key, char, char>> nts::CKeyboard::_inputs = {
    std::tuple(sf::Keyboard::A, 'a', 'A'),
    std::tuple(sf::Keyboard::B, 'b', 'B'),
    std::tuple(sf::Keyboard::C, 'c', 'C'),
    std::tuple(sf::Keyboard::D, 'd', 'D'),
    std::tuple(sf::Keyboard::E, 'e', 'E'),
    std::tuple(sf::Keyboard::F, 'f', 'F'),
    std::tuple(sf::Keyboard::G, 'g', 'G'),
    std::tuple(sf::Keyboard::H, 'h', 'H'),
    std::tuple(sf::Keyboard::I, 'i', 'I'),
    std::tuple(sf::Keyboard::J, 'j', 'J'),
    std::tuple(sf::Keyboard::K, 'k', 'K'),
    std::tuple(sf::Keyboard::L, 'l', 'L'),
    std::tuple(sf::Keyboard::M, 'm', 'M'),
    std::tuple(sf::Keyboard::N, 'n', 'N'),
    std::tuple(sf::Keyboard::O, 'o', 'O'),
    std::tuple(sf::Keyboard::P, 'p', 'P'),
    std::tuple(sf::Keyboard::Q, 'q', 'Q'),
    std::tuple(sf::Keyboard::R, 'r', 'R'),
    std::tuple(sf::Keyboard::S, 's', 'S'),
    std::tuple(sf::Keyboard::T, 't', 'T'),
    std::tuple(sf::Keyboard::U, 'u', 'U'),
    std::tuple(sf::Keyboard::V, 'v', 'V'),
    std::tuple(sf::Keyboard::W, 'w', 'W'),
    std::tuple(sf::Keyboard::X, 'x', 'X'),
    std::tuple(sf::Keyboard::Y, 'y', 'Y'),
    std::tuple(sf::Keyboard::Z, 'z', 'Z'),
    std::tuple(sf::Keyboard::Enter, '\n', '\n'),
    std::tuple(sf::Keyboard::Space, ' ', ' '),
    std::tuple(sf::Keyboard::Comma, ',', '?'),
    std::tuple(sf::Keyboard::Tab, '\t', '\t'),
    std::tuple(sf::Keyboard::Num0, '&', '0'),
    std::tuple(sf::Keyboard::Num1, 'e', '1'),
    std::tuple(sf::Keyboard::Num2, '"', '2'),
    std::tuple(sf::Keyboard::Num3, '\'', '3'),
    std::tuple(sf::Keyboard::Num4, '(', '4'),
    std::tuple(sf::Keyboard::Num5, '-', '5'),
    std::tuple(sf::Keyboard::Num6, 'e', '6'),
    std::tuple(sf::Keyboard::Num7, '_', '7'),
    std::tuple(sf::Keyboard::Num8, 'c', '8'),
    std::tuple(sf::Keyboard::Num9, 'a', '9'),
};
