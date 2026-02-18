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
    _commands[""] = [this]() {exitShell();};
    _commands["display"] = [this]() {display();};
    _commands["simulate"] = [this]() {simulate();};
    _commands["loop"] = [this]() {loop();};
    _commands["exit"] = [this]() {exitShell();};
}

bool nts::Shell::getCommand(std::string &str)
{
    std::string command;
    std::string end;
    std::istringstream stream(str);
    stream >> command >> end;
    if (!end.empty()) {
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
    simulate();
    std::string str;
    std::cout << "> ";
    while (std::getline(std::cin, str)) {
        try {
            if (getCommand(str))
                break;
        } catch (CommandException &e) {
            throw CommandException(str);
        }
        std::cout << "> ";
    }
}

void nts::Shell::displayType(
    std::string type1, std::optional<std::string> type2)
{
    auto iter = _map.begin();
    while (iter != _map.end()) {
        if (iter->second.second == type1
            || (type2.has_value()
            && iter->second.second == type2.value())) {
            std::cout << "  " << iter->first << ": ";
            if (iter->second.first->compute(0) == Undefined)
                std::cout << "U" << std::endl;
            else
                std::cout << iter->second.first->compute(0) << std::endl;
        }
        iter++;
    }
}

void nts::Shell::display()
{
    std::cout << "tick: " << _tick - 1 << std::endl;
    std::cout << "input(s):" << std::endl;
    displayType("input", "clock");
    std::cout << "output(s):" << std::endl;
    displayType("output", {});
}

void nts::Shell::simulate()
{
    _tick += 1;
    changeState();
    auto iter = _map.begin();
    while (iter != _map.end()) {
        if (iter->second.second == "output"
            || iter->second.second == "clock"
            || iter->second.second == "logger") {
            iter->second.first->simulate(_tick);
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
        || (_map.find(name)->second.second != "input"
        && _map.find(name)->second.second != "clock"))
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
        std::istringstream stream(str);
        int state;
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
        auto &tmp = _map.find(change.first)->second;
        tmp.first->getPin(0).setValue(change.second);
        if (tmp.second == "clock" && change.second == nts::True)
            tmp.first->getPin(0).setValue(nts::False);
        else if (tmp.second == "clock" && change.second == nts::False)
            tmp.first->getPin(0).setValue(nts::True);
        _change.pop();
    }
}