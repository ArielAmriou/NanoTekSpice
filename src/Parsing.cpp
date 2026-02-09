/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Parsing
*/

#include "Parsing.hpp"
#include <fstream>

void nts::parsing(std::string fileName)
{
    std::string str;

    if (fileName.ends_with(".nts"))
        throw ParsingException(Error::WRONG_EXTENSION);
    std::ifstream file(fileName);
    if (!file.good())
        throw OpenFailureException();
    file.close();
}
