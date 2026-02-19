/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentException
*/

#ifndef COMPONENTEXCEPTION_HPP_
#define COMPONENTEXCEPTION_HPP_

#include <exception>
#include <string>

namespace nts {

    class NtsException : public std::exception {
        public:
            NtsException(std::string str) : _str(str) {};
            NtsException(std::string str, std::size_t line) :
                _str(str + " Line " + std::to_string(line)) {};
            NtsException(std::string str, std::string path, std::size_t line) :
                _str(str + " At " + path + ":" + std::to_string(line)) {};
            virtual const char *what() const noexcept override
                { return _str.c_str(); };
        private:
            std::string _str;
    };

    class NoSuchPin : public NtsException {
        public:
            NoSuchPin() : NtsException("No such pin available.") {}
    };

    class ConnectionException : public NtsException {
        public:
            ConnectionException() : NtsException(
                "Connection must be between an input and an output.") {};
    };

    class UnknownComponentException : public NtsException {
        public:
            UnknownComponentException() : NtsException("Unkown component.") {};
    };

    class OpenFailureException : public NtsException {
        public:
            OpenFailureException() : NtsException("No such file.") {};
    };
}

#endif /* !COMPONENTEXCEPTION_HPP_ */
