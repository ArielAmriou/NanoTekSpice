/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** tests_parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include "Parsing.hpp"
#include "NtsException.hpp"

#define DEBUG(value) std::cout << "\e[0;35m" << "DEBUG: " <<  "\e[0;37m" << "\t" << value << std::endl;

static void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static const char *test_main(const char *file)
{
    char path[1024] = "tests/testfiles/";
    strcat(path, file);

    try {
        std::string namefile = path;
        std::map<std::string, std::unique_ptr<nts::IComponent>> map;
        nts::Parsing parser(namefile, map);
        parser.parseFile();
    } catch (nts::NtsException &e) {
        std::string *tmp = new std::string(e.what());
        return tmp->c_str();
    }
    return "No Error";
}

Test(ParsingTest, linkInvalid)
{
    cr_assert_str_eq(test_main("linkInvalid.nts"), "Link is not valid. At tests/testfiles/linkInvalid.nts:5");
}

Test(ParsingTest, noChipsets)
{
    cr_assert_str_eq(test_main("noChipsets.nts"), "No chipsets in the circuit.");
}

Test(ParsingTest, noLinks)
{
    cr_assert_str_eq(test_main("noLinks.nts"), "No statement chipsets or links.");
}

Test(ParsingTest, tooMuchInfoChipsets)
{
    cr_assert_str_eq(test_main("tooMuchInfoChipsets.nts"), "Lexical or syntactic errors. At tests/testfiles/tooMuchInfoChipsets.nts:2");
}

Test(ParsingTest, tooMuchInfoLinks)
{
    cr_assert_str_eq(test_main("tooMuchInfoLinks.nts"), "Lexical or syntactic errors. At tests/testfiles/tooMuchInfoLinks.nts:6");
}

Test(ParsingTest, wrongExtension)
{
    cr_assert_str_eq(test_main("wrongExtension"), "Wrong file extension.");
}

Test(ParsingTest, noFile)
{
    cr_assert_str_eq(test_main("no.nts"), "No such file.");
}

Test(ParsingTest, multipleCpnName)
{
    cr_assert_str_eq(test_main("multipleCpnName.nts"), "Chipsets name already use. At tests/testfiles/multipleCpnName.nts:3");
}

Test(ParsingTest, linkToWrongPin)
{
    cr_assert_str_eq(test_main("linkToWrongPin.nts"), "No such pin available. At tests/testfiles/linkToWrongPin.nts:5");
}

Test(ParsingTest, linkTwoOutput)
{
    cr_assert_str_eq(test_main("linkTwoOutput.nts"), "Connection must be between an input and an output. At tests/testfiles/linkTwoOutput.nts:5");
}

Test(ParsingTest, connectUnusedPin)
{
    cr_assert_str_eq(test_main("connectUnusedPin.nts"), "Connection must be between an input and an output. At tests/testfiles/connectUnusedPin.nts:4");
}