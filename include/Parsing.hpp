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
    #include <fstream>
    #include "IComponent.hpp"
    #include "NtsException.hpp"

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
        errorMsg = {
        "Wrong file extension.",
        "No statement chipsets or links.",
        "Lexical or syntactic errors.",
        "Link is not valid.",
        "No chipsets in the circuit.",
        "Chipsets name already use."
    };

    class Parsing {
        public:
            Parsing(std::string &,
                std::map<std::string, std::unique_ptr<nts::IComponent>> &);
            ~Parsing() {_file.close();};

            void parseFile();

            class OpenFailureException : public NtsException {
                public:
                    OpenFailureException() : NtsException("No such file.") {};
            };

            class ParsingException : public NtsException {
                public:
                    ParsingException(Error e) : NtsException(errorMsg[e]) {};
            };
        private:
            std::map<std::string, std::unique_ptr<nts::IComponent>> &_map;
            std::string _path;
            std::ifstream _file;
            void parsingLink(std::string &str);
            std::pair<std::string, std::size_t> isLink(std::string link);
            void parsingChipset(std::string &str);
            void removeComment(std::string &str);
            void parsingLine(std::string &str, bool &chipsets, bool &links);
    };
}

#endif
