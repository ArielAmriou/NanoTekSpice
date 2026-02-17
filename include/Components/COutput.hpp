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
    class COutput: public AComponent {
        public:
            COutput();
            ~COutput() = default;
        private:
            void simulateComponent();
            static const std::vector<Pin> _defaultPins;
    };
}

#endif /* !COMPONENTCOUTPUT_HPP_ */
