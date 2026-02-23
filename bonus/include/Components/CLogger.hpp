/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** CLogger
*/

#ifndef COMPONENTCLOGGER_HPP_
#define COMPONENTCLOGGER_HPP_

#include "AComponent.hpp"

    constexpr std::size_t LOGGERBITS = 8;
    constexpr std::size_t MAXCHARSIZE = 256;
    constexpr int CLOGGERX = 100;
    constexpr int CLOGGERY = 150;
    constexpr int CLOGGERTEXTOFFSET = 20;

namespace nts {
    class CLogger: public AComponent {
        public:
            CLogger(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CLogger() = default;

            void drawComponent(sf::RenderWindow &window) override;

        private:
            void writeInFile(char value);
            void simulateComponent();
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            Tristate _lastClk = Undefined;
            sf::Text _loggerText;
    };
}

#endif /* !COMPONENTCLOGGER_HPP_ */