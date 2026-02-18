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
    #include "Utils.hpp"

namespace nts {
    class Shell {
        public:
            Shell();

            void run();
            
            ComponentMap &getMap() {return _map;}

            class CommandException : public NtsException {
                public:
                    CommandException()
                        : NtsException("Wrong Command.") {};
                    CommandException(std::string cmd)
                        : NtsException("Wrong Command: " + cmd + ".") {};
            };

        private:
            std::size_t _tick;
            ComponentMap _map;
            std::unordered_map<std::string, std::function<void()>> _commands;
            std::queue<std::pair<std::string, Tristate>> _change;
            void display();
            void simulate();
            void loop();
            void changeInput(std::string);
            void exitShell() {};
            bool getCommand(std::string &);
            void displayType(
                std::string type1, std::optional<std::string> type2);
            Tristate getState(std::string);
            void changeState();
    };
}

#endif