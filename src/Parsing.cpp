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
}

std::pair<std::string, std::size_t> nts::Parsing::isLink(std::string link)
{
    size_t pos = link.find(":");
    std::string name;
    std::size_t pin;

    if (pos != std::string::npos)
        link.replace(pos, 1, " ");
    else
        throw ParsingException(nts::Error::LINKINVALID);
    std::istringstream stream(link);
    stream >> name >> pin;
    if (name.empty() || stream.fail())
        throw ParsingException(nts::Error::LINKINVALID);
    return std::make_pair(name, pin);
}

void nts::Parsing::parsingLink(std::string &str)
{
    std::string linkOne;
    std::string linkTwo;
    std::string end;
    std::istringstream stream(str);
    std::pair<std::string, std::size_t> one;
    std::pair<std::string, std::size_t> two;

    stream >> linkOne >> linkTwo >> end;
    if (linkOne.empty() || linkTwo.empty() || !end.empty())
        throw ParsingException(nts::Error::LEXICALORSYNTATIC);
    try {
        one = isLink(linkOne);
        two = isLink(linkTwo);
    } catch (ParsingException &e) {
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

void nts::Parsing::parsing(std::string &fileName)
{
    std::string str;
    std::ifstream file(fileName);
    bool chipsets = false;
    bool links = false;
    
    if (!fileName.ends_with(".nts"))
        throw ParsingException(Error::WRONG_EXTENSION);
    if (!file.good())
        throw OpenFailureException();
    while (std::getline(file, str)) {
        DEBUG(str);
        removeComment(str);
        if (!str.length())
            continue;
        try {
            parsingLine(str, chipsets, links);
        } catch (ParsingException &e) {
            throw e;
        } 
    }
    if (!chipsets || !links)
        throw ParsingException(Error::NO_STATEMENTS);
    file.close();
}
