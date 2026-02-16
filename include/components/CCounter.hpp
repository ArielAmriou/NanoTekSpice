/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCCounter
*/

#ifndef COMPONENTCCOUNTER_HPP_
#define COMPONENTCCOUNTER_HPP_

#include "AComponent.hpp"
#include <list>

namespace nts {
    class CCounter: public AComponent {
        public:
            CCounter();
            ~CCounter() = default;
        private:
            void simulateComponent();
            nts::Tristate _prevC = nts::Tristate::Undefined;
            static const std::vector<Pin> _defaultPins;
            static const std::list<std::size_t> _outputOrder;

            enum pins {
                Q12,
                Q6,
                Q5,
                Q7,
                Q4,
                Q3,
                Q2,
                VSS,
                Q1,
                C,
                R,
                Q9,
                Q8,
                Q10,
                Q11,
                VDD,
            };
    };
}

#endif /* !COMPONENTCCOUNTER_HPP_ */
