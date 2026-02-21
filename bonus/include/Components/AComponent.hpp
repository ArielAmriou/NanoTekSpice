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
            AComponent(const std::string &name, sf::Vector2f pos, sf::Vector2f size, sf::Font &font);

            void simulate(std::size_t tick) noexcept;
            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin);
            Pin &getPin(std::size_t);
            nts::Tristate compute(std::size_t pin);
            void resetOutputs(
                const nts::Tristate value = nts::Tristate::Undefined);

            // Sfml
            Pin &getNPin(size_t n) {return _pins[n];}
            sf::Vector2f getNPinPos(size_t n) {return {_pins[n].getPos().x + _pos.x, _pins[n].getPos().y + _pos.y};}
            void setPos(sf::Vector2f pos) {_pos = {pos.x - _size.x / 2, pos.y - _size.y / 2};}
            sf::Vector2f getPos() const {return _pos;}
            sf::RectangleShape &getChipset() {return _rec;}
            sf::Vector2f getSize() {return _size;}

            void draw(sf::RenderWindow &window);

        protected:
            virtual void simulateComponent() = 0;
            std::vector<Pin> _pins;
            std::size_t _nbPins;
            std::size_t _lastUpdateTick = 0;

            // Sfml
            sf::Vector2f _size;
            sf::RectangleShape _rec;
            sf::Text _text;
            sf::Vector2f _pos;
            std::string _name;
    };
}

#endif /* !ACOMPONENT_HPP_ */
