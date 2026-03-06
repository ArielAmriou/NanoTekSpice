/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentC6Not
*/

#ifndef COMPONENTC6NOT_HPP_
#define COMPONENTC6NOT_HPP_

#include "APartComponent.hpp"

namespace nts {

    constexpr std::size_t C6NOTNBPART = 6;
    constexpr std::size_t C6NOTNBIN = 1;
    constexpr std::size_t C6NOTNBOUT = 1;

    class C6Not: public APartComponent {
        public:
            C6Not();
            ~C6Not() = default;

            enum PinName {
                D1,
                Q1,
                D2,
                Q2,
                D3,
                Q3,
                VSS,
                Q4,
                D4,
                Q5,
                D5,
                Q6,
                D6
            };

        protected:
            const std::vector<std::size_t> getInputPins() override
                {return _inputs;}
            const std::vector<std::size_t> getOutputPins() override
                {return _outputs;}
            void computePart(std::size_t partId) override;

        private:
            static const std::vector<Pin> _defaultPins;
            static const std::vector<std::size_t> _inputs;
            static const std::vector<std::size_t> _outputs;
    };
}

#endif /* !COMPONENTC6NOT_HPP_ */
