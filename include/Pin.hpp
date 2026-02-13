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
            Pin(nts::Mode mode, nts::Tristate value):
                _mode(mode), _value(value), _con() {};
            Pin(nts::Mode mode):
                _mode(mode), _value(nts::Tristate::Undefined), _con() {};
            Pin(const nts::Pin &src):
                _mode(src._mode), _con(), _value(src._value) {};
            nts::Mode getMode() { return this->_mode; };
            nts::Tristate getValue() { return this->_value; };
            void setValue(nts::Tristate value) { this->_value = value; };
            Pin &operator=(const Pin &right) {
                this->_mode = right._mode;
                this->_value = right._value;
                return *this;
            };
            std::optional<Connection> &getConnection() { return _con; };
            void setConnection(IComponent &component, std::size_t pin)
                {_con.emplace(Connection(component, pin));}
        private:
            std::optional<Connection> _con;
            nts::Mode _mode;
            nts::Tristate _value;
    };
}

#endif /* !PIN_HPP_ */
