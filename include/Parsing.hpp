/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Parsing
*/

#ifndef PARSING_HPP
    #define PARSING_HPP

    #include <string>
    #include <array>

namespace nts {

    void parsing(std::string);

    enum Error {
        WRONG_EXTENSION,
        NB_ERROR
    };

    static const std::array<const char *, nts::NB_ERROR> ERROR_MSG = {
        "Wong file extension.",
    };

    class OpenFailureException : public std::exception {
        public:
            const char *what() const throw() {return "No such file.";};
    };

    class ParsingException : public std::exception {
        public:
            ParsingException(Error e) : _e(e) {};
            const char *what() const throw() {return ERROR_MSG[_e];};
        private:
            Error _e;
    };
}

#endif
