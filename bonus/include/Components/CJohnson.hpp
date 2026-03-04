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

    constexpr float CJOHNSONX = 50;
    constexpr float CJOHNSONY = 250;

    class CJohnson: public AComponent {
        public:
            CJohnson(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~CJohnson() = default;
        private:
            void simulateComponent();
            void incrementValues();
            void searchTrue();
            void setValues(nts::Tristate c, nts::Tristate cp);
            nts::Tristate _prevC = nts::Tristate::Undefined;
            nts::Tristate _prevCp = nts::Tristate::Undefined;
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
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
