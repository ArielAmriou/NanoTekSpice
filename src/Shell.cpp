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

nts::Shell::Shell() : _tick(0)
{
    _commands["display"] = [this]() {display();};
    _commands["simulate"] = [this]() {simulate();};
    _commands["loop"] = [this]() {loop();};
    _commands["changeInput"] = [this]() {changeInput();};
    _commands["exit"] = [this]() {exit();};
}

bool nts::Shell::getCommand(std::string &str)
{
    std::string command;
    std::string end;
    std::istringstream stream(str);
    stream >> command >> end;
    if (command.empty() || !end.empty() || !_commands.count(command))
        throw CommandException();
    _commands[command]();
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

void nts::Shell::displayType(std::string type)
{
    auto iter = _map.begin();
    while (iter != _map.end()) {
        if (iter->second.get()->getName() == type) {
            std::cout << "  " << iter->first << ": ";
            if (iter->second.get()->compute(0) == Undefined)
                std::cout << "U" << std::endl;
            else
                std::cout << iter->second.get()->compute(0) << std::endl;
        }
        iter++;
    }
}

void nts::Shell::display()
{
    std::cout << "tick: " << _tick << std::endl;
    std::cout << "inputs(s): " << std::endl;
    displayType("input");
    std::cout << "output(s): " << std::endl;
    displayType("output");
}

void nts::Shell::simulate()
{
    _tick += 1;
}

void nts::Shell::loop()
{
    while (true) {
        simulate();
        display();
    }
}