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
            Shell() {};
            ~Shell() {};

            void run();

            class CommandException : public std::exception {
                public:
                    const char *what() const throw()
                        {return "Wrong Command.";};
            };

            std::map<std::string, std::unique_ptr<nts::IComponent>> &getMap()
                {return _map;};

        private:
            std::map<std::string, std::unique_ptr<nts::IComponent>> _map;
            bool getCommand(std::string &);
    };
}

#endif