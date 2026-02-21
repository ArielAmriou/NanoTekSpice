/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentException
*/

#ifndef COMPONENTEXCEPTION_HPP_
#define COMPONENTEXCEPTION_HPP_

#include <exception>

namespace nts {

    class FontsException : public std::exception {
        public:
            const char *what() const noexcept override
                { return "Error: Can't load Font file."; };
    };

}

#endif /* !COMPONENTEXCEPTION_HPP_ */
