/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** CheckEnv
*/

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "MyGKrellm.hpp"

std::string getEnv(std::string const &key)
{
    char const *val = getenv(key.c_str());
    return ((val == NULL) ? "" : std::string(val));
}

std::string check_inside_var(std::string const &Env_Key, std::string const &Env_Value)
{
    std::string temp = getEnv(Env_Key);

    if (temp == "")
        return "";
    if (temp.find(Env_Value) != 0)
        return "";
    return temp;
}

std::string check_inside_display(std::string const &Env_Key, std::string const &Env_Value, std::string const &Env_Value2)
{
    std::string temp = getEnv(Env_Key);

    if (temp == "")
        return "";
    if (temp.find(Env_Value) == std::string::npos && temp.find(Env_Value2) == std::string::npos)
        return "";
    return temp;
}

int check_env()
{
    if (check_inside_var("TERM", "xterm-256color") == "")
        return 84;
    if (check_inside_var("COLORTERM", "truecolor") == "")
        return 84;
    if (check_inside_display("DISPLAY", ":0", ":0.0") == "")
        return 84;
    return 0;
}

bool check_file_exist(const std::string &s1, const std::string &s2, const std::string &s3)
{
    std::ifstream ifs1(s1);
    std::ifstream ifs2(s1);
    std::ifstream ifs3(s1);

    if (ifs1.fail() || ifs2.fail() || ifs3.fail())
        return false;
    ifs1.close();
    ifs2.close();
    ifs3.close();
    return true;
}

bool MyGKrellm::check(char **argv)
{
    if (check_env() == 84)
        return false;
    if (argv[1] && strcmp(argv[1], "-n") == 0)
        this->mode_ = true;
    if (check_file_exist("./graphics/assets/fonts/bold.otf", "./graphics/assets/fonts/light.otf", "./graphics/assets/fonts/regular.otf") == false)
        return 84;
    return true;
}
