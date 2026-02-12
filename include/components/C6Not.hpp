/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC6Not
*/

#ifndef COMPONENTC6NOT_HPP_
#define COMPONENTC6NOT_HPP_

#include "AComponent.hpp"

namespace nts {
    class C6Not: public AComponent {
        public:
            C6Not();
            ~C6Not() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTC6NOT_HPP_ */
