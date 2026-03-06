/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AGateComponent
*/

#ifndef AGATECOMPONENT_HPP_
#define AGATECOMPONENT_HPP_

#include <functional>
#include "APartComponent.hpp"

namespace nts {

    constexpr float AGATECOMPONENTX = 75;
    constexpr float AGATECOMPONENTY = 150;

    constexpr std::size_t GATECOMPONENTNBPART = 4;
    constexpr std::size_t GATECOMPONENTNBIN = 2;
    constexpr std::size_t GATECOMPONENTNBOUT = 1;

    class AGateComponent: public APartComponent {
        public:
            AGateComponent(sf::Vector2f pos, sf::Font &font, const std::string &name, std::function<Tristate(Tristate, Tristate)>);
            enum PinName {
                D1,
                D2,
                Q1,
                Q2,
                D3,
                D4,
                VSS,
                D5,
                D6,
                Q3,
                Q4,
                D7,
                D8,
                VDD,
            };
            
        protected:
            const std::vector<std::size_t> getInputPins() override
                {return _inputs;}
            const std::vector<std::size_t> getOutputPins() override
                {return _outputs;}
            void computePart(std::size_t partId) override;

        private:
            static const std::vector<std::tuple<nts::Mode, sf::Vector2f, std::string, nts::Tristate>> _defaultPins;
            static const std::vector<std::size_t> _inputs;
            static const std::vector<std::size_t> _outputs;
            std::function<Tristate(Tristate, Tristate)> _func;
    };
}

#endif /* !COMPONENTCAND_HPP_ */
