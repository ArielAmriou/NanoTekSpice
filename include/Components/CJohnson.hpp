/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCJohnson
*/

#ifndef COMPONENTCJOHNSON_HPP_
#define COMPONENTCJOHNSON_HPP_

#include "AComponent.hpp"
#include <list>

namespace nts {
    class CJohnson: public AComponent {
        public:
            CJohnson();
            ~CJohnson() = default;
        private:
            void simulateComponent();
            void incrementValues();
            void searchTrue();
            nts::Tristate _prevC = nts::Tristate::Undefined;
            static const std::vector<Pin> _defaultPins;
            static const std::list<std::size_t> _outputOrder;

            enum pins {
                Q5,
                Q1,
                Q0,
                Q2,
                Q6,
                Q7,
                Q3,
                VSS,
                Q8,
                Q4,
                Q9,
                CO,
                CP,
                CLK,
                MR,
                VDD,
            };
    };
}

#endif /* !COMPONENTCJOHNSON_HPP_ */
