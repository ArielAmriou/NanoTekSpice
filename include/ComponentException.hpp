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
    class NoSuchPin: std::exception {
        public:
            const char *what() const noexcept override { return "No such pin available"; };
    };
    class UnknownComponentException : public std::exception {
        public:
            const char *what() const noexcept override { return "Unkown component"; };
    };
}

#endif /* !COMPONENTEXCEPTION_HPP_ */
