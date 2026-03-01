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
            Pin(nts::Mode mode, nts::Tristate value, sf::Vector2f pos, sf::Font &font, std::string name);
            Pin(nts::Mode mode, sf::Vector2f pos, sf::Font &font, std::string name);
            Pin(const nts::Pin &src):
                _mode(src._mode), _con(), _value(src._value), _pos(src._pos), _circle(src._circle), _text(src._text), _rec(src._rec) {};

            nts::Mode getMode() const { return this->_mode; };
            nts::Tristate getValue() const { return this->_value; };
            void setValue(nts::Tristate value) { this->_value = value; };
            std::optional<Connection> &getConnection() { return _con; };
            void setConnection(
                std::reference_wrapper<IComponent>, std::size_t pin);
            Pin &operator=(const Pin &right);

            // Sfml
            void draw(sf::RenderWindow &window, sf::Vector2f pos);
            void drawConnection(sf::RenderWindow &window, sf::Vector2f pos);
            void drawLabel(sf::RenderWindow &window);

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
            sf::Vector2f _size = {50, 25};
            sf::RectangleShape _rec;
            sf::Text _text;
    };
}

#endif /* !PIN_HPP_ */
