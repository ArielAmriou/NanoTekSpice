/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** tests_component
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>

#include "NanoTekSpice.hpp"
#include "Parsing.hpp"
#include "Shell.hpp"
#include "NtsException.hpp"

#define FINE "No Error"

#define DEBUG(value) std::cout << "\e[0;35m" << "DEBUG: " <<  "\e[0;37m" << "\t" << value << std::endl;

static void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static const char *test_main(const char *initfile, const char *testfile)
{
    char init[1024] = "tests/testfiles/";
    strcat(init, initfile);
    char path[1024] = "tests/testCommands/";
    strcat(path, testfile);
    
    FILE *input = fopen(path, "r");
    cr_assert_not_null(input);

    int fd = fileno(input);
    dup2(fd, STDIN_FILENO);

    try {
        std::string filename = init;
        nts::Shell shell;
        nts::Parsing parser(filename, shell.getMap());
        parser.parseFile();
        shell.run();
    } catch (nts::NtsException &e) {
        std::string *tmp = new std::string(e.what());
        return tmp->c_str();
    }

    fclose(input);
    return FINE;
}

static std::string readFile(const char *name, bool test)
{
    std::string content;
    std::string str;

    char path[1024] = "";
    if (test)
        strcat(path, "tests/testResult/");
    strcat(path, name);

    bool first = false;

    std::ifstream file(path);
    while (std::getline(file, str)) {
        if (first)
            content += "\n" + str;
        else {
            content += str;
            first = true;
        }
    }
    file.close();
    return content;
}

Test(TestFiles, wrongCommand, .init = redirect_all_std)
{
    cr_assert_str_eq(test_main("and.nts", "wrongCommand"), "Wrong Command: wrongCommand.");
}

Test(TestFiles, notAnInput, .init = redirect_all_std)
{
    cr_assert_str_eq(test_main("and.nts", "notAnInput"), "Wrong Command: o=1.");
}

Test(TestFiles, valueNotNb, .init = redirect_all_std)
{
    cr_assert_str_eq(test_main("and.nts", "valueNotNb"), "Wrong Command: c=l.");
}

Test(TestFiles, CPN_not, .init = redirect_all_std)
{
    std::string test = "not";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), "notCommand"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_and, .init = redirect_all_std)
{
    std::string test = "and";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), "simpleCommand"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_or, .init = redirect_all_std)
{
    std::string test = "or";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), "simpleCommand"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_xor, .init = redirect_all_std)
{
    std::string test = "xor";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), "simpleCommand"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_true, .init = redirect_all_std)
{
    std::string test = "true";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), "display"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_false, .init = redirect_all_std)
{
    std::string test = "false";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), "display"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_logger, .init = redirect_all_std)
{
    std::string test = "logger";
    std::string ext = test + ".nts";
    
    cr_assert_str_eq(test_main(ext.c_str(), "logger"), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str("> > > > > > > ");
    auto log = readFile("log.bin", false).c_str();
    cr_assert_str_eq(log, "A");
}

Test(TestFiles, CPN_selector, .init = redirect_all_std)
{
    std::string test = "selector";
    std::string ext = "4512.nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), test.c_str()), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}

Test(TestFiles, CPN_decoder, .init = redirect_all_std)
{
    std::string test = "decoder";
    std::string ext = test + ".nts";
    
    auto result = readFile(test.c_str(), true);
    cr_assert_str_eq(test_main(ext.c_str(), test.c_str()), FINE);
    fflush(stdout);
    cr_assert_stdout_eq_str(result.c_str());
}