/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Shell
*/

#include <iostream>
#include <iomanip>
#include "Shell.hpp"
#include "Pin.hpp"

nts::Shell::Shell() : _tick(0)
{
    _commands["display"] = [this]() {display();};
    _commands["simulate"] = [this]() {simulate();};
    _commands["loop"] = [this]() {loop();};
    _commands["exit"] = [this]() {exit();};
}

bool nts::Shell::getCommand(std::string &str)
{
    std::string command;
    std::string end;
    std::istringstream stream(str);
    stream >> command >> end;
    if (command.empty() || !end.empty()) {
        throw CommandException();
    } else if (!_commands.count(command)) {
        try {
            changeInput(command);
        } catch (CommandException &e) {
            throw e;
        }
    } else
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

void nts::Shell::displayType(
    std::string type1, std::optional<std::string> type2)
{
    auto iter = _map.begin();
    while (iter != _map.end()) {
        if (iter->second.get()->getName() == type1
            || (type2.has_value()
            && iter->second.get()->getName() == type2.value())) {
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
    displayType("input", "clock");
    std::cout << "output(s): " << std::endl;
    displayType("output", {});
}

void nts::Shell::simulate()
{
    _tick += 1;
    changeState();
    auto iter = _map.begin();
    while (iter != _map.end()) {
        if (iter->second.get()->getName() == "output") {
            iter->second.get()->simulate(_tick);
        }
        iter++;
    }
}

void nts::Shell::loop()
{
    while (true) {
        simulate();
        display();
    }
}

void nts::Shell::changeInput(std::string str)
{
    size_t pos = str.find("=");
    if (pos != std::string::npos)
        str.replace(pos, 1, " ");
    else
        throw CommandException();
    std::string name;
    std::string value;
    std::string end;
    std::istringstream stream(str);
    stream >> name >> value >> end;
    if (name.empty() || value.empty() || !end.empty())
        throw CommandException();
    if (!_map.count(name)
        || (_map.find(name)->second.get()->getName() != "input"
        && _map.find(name)->second.get()->getName() != "clock"))
        throw CommandException();
    try {
        _change.push(std::make_pair(name, getState(value)));
    } catch (CommandException &e) {
        throw e;
    }
}

nts::Tristate nts::Shell::getState(std::string str)
{
    Tristate value;

    if (str == "U")
        value = Undefined;
    else {
        int state;
        std::istringstream stream(str);
        stream >> state;
        if (stream.fail() || (state != true && state != false))
            throw CommandException();
        if (state)
            value = True;
        else
            value = False;
    }
    return value;
}
void nts::Shell::changeState()
{
    while (!_change.empty()) {
        std::pair<std::string, nts::Tristate> change = _change.front();
        _map.find(change.first)->
            second.get()->getPin(0).setValue(change.second);
        _change.pop();
    }
}