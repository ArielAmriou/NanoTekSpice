/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CPictures
*/

#include <fstream>
#include <cmath>
#include <dirent.h>
#include "CPictures.hpp"
#include "NtsException.hpp"

nts::CPictures::CPictures(sf::Vector2f pos, sf::Font &font, const std::string &name)
    : AComponent(name, pos, {CPICTURESX, CPICTURESY}, font, _defaultPins)
{
    this->_nbPins = this->_pins.size();
    _textOffset = {-CPICTURESTEXTOFFSET, 0};
    _pictures.clear();
    
    auto rawFiles = getFiles();
    for (const auto &filename : rawFiles) {
        std::string key = filename.substr(0, filename.size() - 4);
        std::array<std::array<Tristate, BIT>, PICTURESMEM> mem;
        for (auto &cell : mem)
            cell.fill(nts::Undefined);
        std::ifstream file("pictures/" + filename, std::ios::binary);
        if (!file.is_open())
            throw OpenFailureException();
        for (std::size_t i = 0; i < PICTURESMEM; i++) {
            int byte = file.get();
            if (byte == EOF)
                break;
            for (std::size_t j = 0; j < BIT; j++) {
                if ((static_cast<const char>(byte) >> j) & True == True)
                    mem[i][j] = True;
                else
                    mem[i][j] = False;
            }
        }
        _pictures[key] = mem;
    }
    _current = _pictures.begin()->first;
    _pictureName.setFont(font);
    _pictureName.setCharacterSize(20);
    _pictureName.setStyle(sf::Text::Bold);
    _pictureName.setString(_current);
    sf::FloatRect rc = _pictureName.getLocalBounds();
    _pictureName.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    _pictureName.rotate(-90);
    _pictureName.setFillColor(sf::Color::Black);
}

std::vector<std::string> nts::CPictures::getFiles()
{
    std::vector<std::string> rawFiles;
    struct dirent* entry;
    DIR* dir = opendir("pictures");

    if (!dir)
        throw OpenFailureException();
    while ((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;
        if (name.size() > 4 && name.substr(name.size() - 4) == ".raw")
            rawFiles.push_back(entry->d_name);
    }
    closedir(dir);
    if (rawFiles.empty())
        throw OpenFailureException();
    return rawFiles;
}

void nts::CPictures::simulateComponent()
{
    int adr = 0;
    bool undefined = false;
    for (std::size_t i = 0; i < NBPICTURESADR; i++) {
        Tristate state = _pins[i].getValue();
        if (state == Undefined) {
            undefined = true;
            break;
        }
        adr += state * static_cast<int>(std::pow(2, i));
    }
    Tristate lower = !_pins[NBPICTURESADR].getValue() & _lastNext;
    _lastNext = _pins[NBPICTURESADR].getValue();
    if (lower == True) {
        auto tmp = _pictures.find(_current);
        ++tmp;
        if (tmp == _pictures.end())
            tmp = _pictures.begin();
        _current = tmp->first;
        _pictureName.setString(_current);
        sf::FloatRect rc = _pictureName.getLocalBounds();
        _pictureName.setOrigin(rc.left + rc.width / 2, rc.top + rc.height / 2);
    }
    if (!undefined) {
        for (std::size_t i = NBPICTURESADR + 1; i < NBPICTURESADR + 1 + NBPICTURESCOLOR; i++) {
            auto tmp = _pictures.find(_current)->second[adr][i - NBPICTURESADR - 1];
            _pins[i].setValue(tmp);
        }
    }
}

void nts::CPictures::drawComponent(sf::RenderWindow &window)
{
    _pictureName.setPosition({_pos.x + _size.x / 2 - _textOffset.x, _pos.y + _size.y / 2});
    window.draw(_pictureName);
}

const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> nts::CPictures::_defaultPins = {
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 1}, "A0", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 2}, "A1", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 3}, "A2", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 4}, "A3", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 5}, "A4", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 6}, "A5", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 7}, "A6", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 8}, "A7", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 9}, "A8", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 10}, "A9", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 11}, "A10", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 12}, "A11", nts::Undefined},
    {nts::Mode::InputMode, {SIDEOFFSET, CPICTURESY / 14 * 13}, "next", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 1}, "C0", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 2}, "C1", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 3}, "C2", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 4}, "C3", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 5}, "C4", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 6}, "C5", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 7}, "C6", nts::Undefined},
    {nts::Mode::OutputMode, {CPICTURESX - SIDEOFFSET, CPICTURESY / 9 * 8}, "C7", nts::Undefined},

};
