/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCPictures
*/

#ifndef COMPONENTCPICTURES_HPP_
#define COMPONENTCPICTURES_HPP_

#include <array>
#include <map>
#include "AComponent.hpp"
#include "Utils.hpp"

namespace nts {

    constexpr int PICTURESMEM = 4096;
    constexpr float CPICTURESX = 100;
    constexpr float CPICTURESY = 200;
    constexpr float CPICTURESTEXTOFFSET = CPICTURESX / 2 - (SIDEOFFSET * 4);
    constexpr int NBPICTURESADR = 12;
    constexpr int NBPICTURESCOLOR = 8;

    class CPictures: public AComponent {
        public:
            CPictures(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CPictures() = default;

            void drawComponent(sf::RenderWindow &window) override;

        private:
            void simulateComponent();
            std::vector<std::string> getFiles();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            std::map<std::string, std::array<std::array<Tristate, BIT>, PICTURESMEM>> _pictures;

            std::string _current;
            nts::Tristate _lastNext;
            sf::Text _pictureName;
    };
}

#endif /* !COMPONENTCPICTURES_HPP_ */
