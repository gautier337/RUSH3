/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** Usage
*/

#include <iostream>
#include <fstream>

void display_help(const std::string &file)
{
    std::ifstream ifs(file);

    if (ifs.is_open()) {
        std::cout << ifs.rdbuf();
    }
}
