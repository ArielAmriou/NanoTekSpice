/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** APartComponent
*/

#ifndef APARTCOMPONENT_HPP_
#define APARTCOMPONENT_HPP_

#include <vector>
#include "AComponent.hpp"

namespace nts {
    class APartComponent : public AComponent {
        public:
            APartComponent(std::size_t nbPart, std::size_t inputsPerPart,
                std::size_t outputsPerPart);
            ~APartComponent() = default;

            void simulate(std::size_t tick) noexcept override;

        protected:
            virtual const std::vector<std::size_t> getInputPins() = 0;
            virtual const std::vector<std::size_t> getOutputPins() = 0;
            virtual void computePart(std::size_t partId) = 0;

        private:
            void simulatePart(std::size_t id, std::size_t tick);
            void simulateIntern(std::size_t id, std::size_t tick);
            std::size_t findOutputPart(std::size_t outputPin);
            std::size_t _nbPart;
            std::size_t _inputsPerPart;
            std::size_t _outputsPerPart;
            std::vector<std::size_t> _partsLastComputedTick;
    };
}

#endif /* !APARTCOMPONENT_HPP_ */