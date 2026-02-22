/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <SFML/Graphics.hpp>
#include <cstddef>
#include <memory>
#include "IComponent.hpp"

namespace nts {
    class Connection {
        public:
            Connection(std::reference_wrapper<IComponent> component,
                std::size_t pin): _component(component), _pin(pin), _line(sf::LinesStrip, 2) {};
            std::reference_wrapper<IComponent>
                getComponent() { return _component; };
            std::size_t getPin() { return _pin; };

            // Sfml
            void draw(sf::RenderWindow &window, sf::Vector2f pos);

        private:
            std::reference_wrapper<IComponent> _component;
            std::size_t _pin;

            // Sfml
            sf::VertexArray _line;
    };
}

#endif /* !CONNECTION_HPP_ */
