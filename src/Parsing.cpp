/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Parsing
*/

#include <iomanip>
#include "Parsing.hpp"
#include "NanoTekSpice.hpp"
#include "ComponentFactory.hpp"

nts::Parsing::Parsing(std::string &fileName,
    std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
    : _file(fileName), _path(fileName), _map(map)
{
    if (!_file.good())
        throw OpenFailureException();
    if (!fileName.ends_with(".nts")) {
        _file.close();
        throw ParsingException(Error::WRONG_EXTENSION);
    }
}

void nts::Parsing::removeComment(std::string &str)
{
    size_t pos = str.find("#");
    if (pos != std::string::npos)
        str.replace(pos, str.length() - pos, "\0");
}

void nts::Parsing::parsingChipset(std::string &str)
{
    std::string type;
    std::string name;
    std::string end;
    std::istringstream stream(str);
    stream >> type >> name >> end;
    if (type.empty() || name.empty() || !end.empty())
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
    if (_map.count(name))
        throw ParsingException(nts::Error::NAMEISUSE);
    try {
        _map.insert({name, nts::ComponentFactory::createComponent(type)});
    } catch (NtsException &e) {
        throw e;
    }
}

std::pair<std::string, std::size_t> nts::Parsing::isLink(std::string link)
{
    size_t pos = link.find(":");
    if (pos != std::string::npos)
        link.replace(pos, 1, " ");
    else
        throw ParsingException(nts::Error::LINKINVALID);
    std::istringstream stream(link);
    std::string name;
    std::size_t pin;
    stream >> name >> pin;
    if (name.empty() || stream.fail() || pin < 1)
        throw ParsingException(nts::Error::LINKINVALID);
    if (!_map.count(name))
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
    return std::make_pair(name, pin - 1);
}

void nts::Parsing::parsingLink(std::string &str)
{
    std::string linkOne;
    std::string linkTwo;
    std::string end;
    std::istringstream stream(str);
    stream >> linkOne >> linkTwo >> end;
    if (linkOne.empty() || linkTwo.empty() || !end.empty())
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
    try {
        std::pair<std::string, std::size_t> one;
        std::pair<std::string, std::size_t> two;
        one = isLink(linkOne);
        two = isLink(linkTwo);
        _map.find(one.first)->second.get()->setLink(
            one.second, *_map.find(two.first)->second.get(), two.second);
    } catch (NtsException &e) {
        throw e;
    }
}

void nts::Parsing::parsingLine(std::string &str, bool &chipsets, bool &links)
{
    bool correct = false;
    if (str == ".chipsets:" && !chipsets) {
        chipsets = true;
        correct = true;
    }
    if (str == ".links:" && chipsets && !links) {
        links = true;
        correct = true;
    }
    try {
        if (chipsets && !links && !correct) {
            parsingChipset(str);
            correct = true;
        } else if (chipsets && links && !correct) {
            parsingLink(str);
            correct = true;
        }
    } catch (ParsingException &e) {
        throw e;
    }
    if (!correct)
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
}

void nts::Parsing::parseFile()
{
    std::string str;
    bool chipsets = false;
    bool links = false;
    for (std::size_t i = 0; std::getline(_file, str); i++) {
        removeComment(str);
        if (!str.length())
            continue;
        try {
            parsingLine(str, chipsets, links);
        } catch (NtsException &e) {
            throw NtsException(e.what(), _path, i + 1);
        }
        if (links && !_map.size())
            throw ParsingException(nts::Error::NOCHIPSETS);
    }
    if (!chipsets || !links)
        throw ParsingException(Error::NO_STATEMENTS);
}
