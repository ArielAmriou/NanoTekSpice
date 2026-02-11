/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include <vector>
#include <optional>
#include <utility>

namespace nts {
    class AComponent: public IComponent {
        public:
            AComponent(std::string name) : _name(name) {};
            void simulate(std::size_t tick) noexcept;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) noexcept;
            nts::Mode getPinMode(std::size_t pin);
            std::string getName() const {return _name;};
        protected:
            std::vector<std::pair<std::string, nts::Mode>> _pins;
            std::size_t _nbPins;
            std::string _name;
    };
}

#endif /* !ACOMPONENT_HPP_ */
