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
    #include <functional>
    #include <unordered_map>
    #include <queue>
    #include <optional>
    #include "IComponent.hpp"

namespace nts {
    class Shell {
        public:
            Shell();
            ~Shell() {};

            void run();

            class CommandException : public std::exception {
                public:
                    const char *what() const throw()
                        {return "Wrong Command.";};
            };

            void display(void);
            void simulate(void);
            void loop(void);
            void changeInput(std::string);
            void exit(void) {};

            std::map<std::string, std::unique_ptr<nts::IComponent>> &getMap()
                {return _map;};

        private:
            std::size_t _tick;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _map;
            std::unordered_map<std::string, std::function<void()>> _commands;
            std::queue<std::pair<std::string, Tristate>> _change;
            bool getCommand(std::string &);
            void displayType(std::string type1, std::optional<std::string> type2);
            Tristate getState(std::string);
            void changeState();
    };
}

#endif