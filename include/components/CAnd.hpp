/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCAnd
*/

#ifndef COMPONENTCAND_HPP_
#define COMPONENTCAND_HPP_

#include "AComponent.hpp"

namespace nts {
    class CAnd: public AComponent {
        public:
            CAnd();
            ~CAnd() = default;
        private:
            void simulateComponent(void);
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCAND_HPP_ */
