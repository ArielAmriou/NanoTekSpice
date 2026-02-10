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

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static const char *test_main(const char *file)
{
    char path[1024] = "tests/testfiles/";
    strcat(path, file);

    try {
        nts::Parsing parser;
        std::string namefile = path;
        std::map<std::string, std::unique_ptr<nts::IComponent>> map;
        parser.parsing(namefile, map);
    } catch (std::exception &e) {
        return e.what();
    }
    return "No Error";
}

Test(ParsingTest, linkInvalid)
{
    cr_assert_str_eq(test_main("linkInvalid.nts"), "Link is not valid.");
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
    cr_assert_str_eq(test_main("tooMuchInfoChipsets.nts"), "Lexical or syntactic errors.");
}

Test(ParsingTest, tooMuchInfoLinks)
{
    cr_assert_str_eq(test_main("tooMuchInfoLinks.nts"), "Lexical or syntactic errors.");
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
    cr_assert_str_eq(test_main("multipleCpnName.nts"), "Chipsets name already use.");
}