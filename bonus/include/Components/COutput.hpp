/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCOutput
*/

#ifndef COMPONENTCOUTPUT_HPP_
#define COMPONENTCOUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {

    constexpr float COUTPUTX = 50;
    constexpr float COUTPUTY = 50;

    class COutput: public AComponent {
        public:
            COutput(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~COutput() = default;
        private:
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
    };
}

#endif /* !COMPONENTCOUTPUT_HPP_ */
