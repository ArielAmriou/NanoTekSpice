/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "Connection.hpp"
#include <optional>

namespace nts {
    class Pin {
        public:
            Pin(nts::Mode mode, nts::Tristate value, sf::Vector2f pos):
                _mode(mode), _value(value), _con(), _pos(pos) {_circle.setOrigin(5, 5);};
            Pin(nts::Mode mode, sf::Vector2f pos):
                _mode(mode), _value(nts::Tristate::Undefined), _con(), _pos(pos) {_circle.setOrigin(5, 5);};
            Pin(const nts::Pin &src):
                _mode(src._mode), _con(), _value(src._value), _pos(src._pos), _circle(src._circle) {};

            nts::Mode getMode() const { return this->_mode; };
            nts::Tristate getValue() const { return this->_value; };
            void setValue(nts::Tristate value) { this->_value = value; };
            std::optional<Connection> &getConnection() { return _con; };
            void setConnection(
                std::reference_wrapper<IComponent>, std::size_t pin);
            Pin &operator=(const Pin &right);

            // Sfml
            void draw(sf::RenderWindow &window, sf::Vector2f pos);

            sf::CircleShape &getPin() {return _circle;};
            sf::Vector2f getPos() {return _pos;}
            void resetCon() {_con = std::nullopt;}

        private:
            std::optional<Connection> _con;
            nts::Mode _mode;
            nts::Tristate _value;

            // Sfml
            sf::CircleShape _circle;
            sf::Vector2f _pos;
    };
}

#endif /* !PIN_HPP_ */
