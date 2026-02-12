/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCTrue
*/

#ifndef COMPONENTCTRUE_HPP_
#define COMPONENTCTRUE_HPP_

#include "AComponent.hpp"

namespace nts {
    class CTrue: public AComponent {
        public:
            CTrue();
            ~CTrue() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCTRUE_HPP_ */
