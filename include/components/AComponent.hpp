/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include "ComponentException.hpp"
#include "Pin.hpp"
#include <vector>
#include <utility>
#include <memory>

namespace nts {
    class AComponent: public IComponent {
        public:
            AComponent(const std::string &name): _name(name) {};
            AComponent(): _name(""), _nbPins(0), _pins(std::vector<Pin>()) {};
            void simulate(std::size_t tick) noexcept;
            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin);
            nts::Mode getPinMode(std::size_t pin);
            std::string getName() const {return _name;};
            Pin &getPin(std::size_t);
            nts::Tristate compute(std::size_t pin);
            std::size_t getNbPin() const {return _nbPins;}
        protected:
            virtual nts::Tristate
                computeComponent(std::size_t pin) noexcept = 0;
            std::vector<Pin> _pins;
            std::size_t _nbPins;
            std::string _name;
    };
}

#endif /* !ACOMPONENT_HPP_ */
