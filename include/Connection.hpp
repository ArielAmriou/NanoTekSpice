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
            Connection(std::unique_ptr<IComponent> component, std::size_t pin):
                _component(component.get()), _pin(pin) {};
            Connection(): _component(nullptr), _pin(0) {};
            IComponent &getComponent() { return *_component; };
            std::size_t getPin() { return _pin; };
        private:
            std::unique_ptr<IComponent> _component;
            std::size_t _pin;
    };
}

#endif /* !CONNECTION_HPP_ */
