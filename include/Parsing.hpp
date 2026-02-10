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
    #include <map>
    #include <memory>
    #include "IComponent.hpp"

namespace nts {

    enum Error {
        WRONG_EXTENSION,
        NO_STATEMENTS,
        LEXICALORSYNTATIC,
        LINKINVALID,
        NOCHIPSETS,
        NAMEISUSE,
        NB_ERROR
    };

    static const std::array<const std::string, nts::Error::NB_ERROR>
        ERROR_MSG = {
        "Wrong file extension.",
        "No statement chipsets or links.",
        "Lexical or syntactic errors.",
        "Link is not valid.",
        "No chipsets in the circuit.",
        "Chipsets name already use."
    };

    class Parsing {
        public:
            void parsing(std::string &,
                std::map<std::string, std::unique_ptr<nts::IComponent>> &);

            
            class OpenFailureException : public std::exception {
                public:
                    const char *what() const throw() {return "No such file.";};
            };

            class ParsingException : public std::exception {
                public:
                    ParsingException(Error e) : _e(e) {};
                    const char *what() const throw()
                        {return nts::ERROR_MSG[_e].c_str();};
                private:
                    Error _e;
            };
        private:
            void parsingLink(std::string &str,
                std::map<std::string, std::unique_ptr<nts::IComponent>> &map);
            std::pair<std::string, std::size_t> isLink(std::string link,
                std::map<std::string, std::unique_ptr<nts::IComponent>> &map);
            void parsingChipset(std::string &str, std::map<std::string,
                std::unique_ptr<nts::IComponent>> &map);
            void removeComment(std::string &str);
            void parsingLine(std::string &str, bool &chipsets, bool &links,
                std::map<std::string, std::unique_ptr<nts::IComponent>> &map);
    };
}

#endif
