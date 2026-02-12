/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <cstddef>
#include <memory>
#include "IComponent.hpp"

namespace nts {
    class Connection {
        public:
            Connection(IComponent &component, std::size_t pin):
                _component(component), _pin(pin) {};
            IComponent &getComponent() { return _component; };
            std::size_t getPin() { return _pin; };
        private:
            IComponent &_component;
            std::size_t _pin;
    };
}

#endif /* !CONNECTION_HPP_ */
