/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <vector>
#include <utility>
#include <memory>
#include "IComponent.hpp"
#include "NtsException.hpp"
#include "Pin.hpp"

namespace nts {
class AComponent: public IComponent {
        public:
            AComponent(): _lastUpdateTick(0) {};
            void simulate(std::size_t tick) noexcept;
            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin);
            Pin &getPin(std::size_t);
            nts::Tristate compute(std::size_t pin);
            void resetOutputs(
                const nts::Tristate value = nts::Tristate::Undefined);

        protected:
            virtual void simulateComponent() = 0;
            std::vector<Pin> _pins;
            std::size_t _nbPins;
            std::size_t _lastUpdateTick;
    };
}

#endif /* !ACOMPONENT_HPP_ */
