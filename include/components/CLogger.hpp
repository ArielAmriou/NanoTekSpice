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

namespace nts {
    class CLogger: public AComponent {
        public:
            CLogger();
            ~CLogger() = default;
        private:
            void writeInFile(char value);
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
            Tristate _lastClk = Undefined;
    };
}

#endif /* !COMPONENTCLOGGER_HPP_ */