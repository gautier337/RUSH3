/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** main
*/

#include "MyGKrellm.hpp"

int main(int argc, char **argv, char **env)
{
    MyGKrellm a;

    if (argc == 0 || !argv || !(*argv) || !env || !(*env))
        return 84;
    if (a.check(argv) == false)
        return 84;
    return a.launch();
}
