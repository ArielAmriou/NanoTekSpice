/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Shell
*/

#ifndef SHELL_HPP
    #define SHELL_HPP

    #include <map>
    #include <string>
    #include <memory>
    #include "IComponent.hpp"

namespace nts {
    class Shell {
        public:
            void shell(
                std::map<std::string, std::unique_ptr<nts::IComponent>> &);
            
            class CommandException : public std::exception {
                public:
                    const char *what() const throw()
                        {return "Wrong Command.";};
            };

        private:
            bool getCommand(std::string &);
    };
}

#endif