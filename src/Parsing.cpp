/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Parsing
*/

#include <fstream>
#include <iomanip>
#include "Parsing.hpp"
#include "NanoTekSpice.hpp"
#include "ComponentFactory.hpp"

void nts::Parsing::removeComment(std::string &str)
{
    size_t pos = str.find("#");
    if (pos != std::string::npos)
        str.replace(pos, str.length() - pos, "\0");
}

void nts::Parsing::parsingChipset(std::string &str,
    std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
    std::string type;
    std::string name;
    std::string end;
    std::istringstream stream(str);
    stream >> type >> name >> end;
    if (type.empty() || name.empty() || !end.empty())
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
    if (map.count(name))
        throw ParsingException(nts::Error::NAMEISUSE);
    try {
        map.insert({name, nts::ComponentFactory::createComponent(type)});
    } catch (std::exception &e) {
        throw e;
    }
}

std::pair<std::string, std::size_t> nts::Parsing::isLink(std::string link,
    std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
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
    if (name.empty() || stream.fail())
        throw ParsingException(nts::Error::LINKINVALID);
    return std::make_pair(name, pin);
}

void nts::Parsing::parsingLink(std::string &str,
    std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
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
        one = isLink(linkOne, map);
        two = isLink(linkTwo, map);
    } catch (ParsingException &e) {
        throw e;
    }
}

void nts::Parsing::parsingLine(std::string &str, bool &chipsets, bool &links,
    std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
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
            parsingChipset(str, map);
            correct = true;
        } else if (chipsets && links && !correct) {
            parsingLink(str, map);
            correct = true;
        }
    } catch (ParsingException &e) {
        throw e;
    }
    if (!correct)
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
}

void nts::Parsing::parsing(std::string &fileName,
    std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
    std::ifstream file(fileName);
    if (!fileName.ends_with(".nts"))
        throw ParsingException(Error::WRONG_EXTENSION);
    if (!file.good())
        throw OpenFailureException();
    std::string str;
    bool chipsets = false;
    bool links = false;
    while (std::getline(file, str)) {
        removeComment(str);
        if (!str.length())
            continue;
        try {
            parsingLine(str, chipsets, links, map);
        } catch (ParsingException &e) {
            throw e;
        } 
        if (links && !map.size())
            throw ParsingException(nts::Error::NOCHIPSETS);
    }
    if (!chipsets || !links)
        throw ParsingException(Error::NO_STATEMENTS);
    file.close();
}
