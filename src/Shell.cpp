/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Shell
*/

#include <iostream>
#include <iomanip>
#include "Shell.hpp"
#include "Input.hpp"

bool nts::Shell::getCommand(std::string &str)
{
    std::string command;
    std::string end;
    std::istringstream stream(str);
    stream >> command >> end;
    if (command.empty() || !end.empty())
        throw CommandException();
    return command == "exit";
}

void nts::Shell::run()
{
    std::string str;
    std::cout << "> ";
    while (std::getline(std::cin, str)) {
        try {
            if (getCommand(str))
                break;
        } catch (CommandException &e) {
            throw e;
        }
        std::cout << "> ";
    }
}
