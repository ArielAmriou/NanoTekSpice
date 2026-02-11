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
            Pin(nts::Mode mode): _mode(mode), _con() {};
            Pin(const nts::Pin &src): _mode(src._mode), _con() {};
            nts::Mode getMode(void) { return this->_mode; };
            nts::Tristate getValue(void) { return this->_value; };
            void setValue(nts::Tristate value) { this->_value = value; };
            Pin &operator=(const Pin &right) {
                this->_mode = right._mode;
                return *this;
            };
        private:
            std::optional<Connection> _con;
            nts::Mode _mode;
            nts::Tristate _value = nts::Undefined;
    };
}

#endif /* !PIN_HPP_ */
