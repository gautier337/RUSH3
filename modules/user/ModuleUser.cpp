/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleUser
*/

#include "ModuleUser.hpp"

ModuleUser::ModuleUser()
{
    char *temp = getlogin();
    if (temp)
        this->UserName_ = std::string(temp);
}

void ModuleUser::refreshData()
{
    return;
}

std::string ModuleUser::getData() const
{
    return this->UserName_;
}
