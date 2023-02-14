/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleKernel
*/

#include "ModuleKernel.hpp"

ModuleKernel::ErrorKernel::ErrorKernel(const std::string &m_what) : name{m_what}
{
}

std::string ModuleKernel::ErrorKernel::getErrorName() const
{
    return this->name;
}

const char *ModuleKernel::ErrorKernel::what() const noexcept
{
    return name.c_str();
}

ModuleKernel::ModuleKernel()
{
    if (uname(&uts) < 0) {
        throw ErrorKernel("Failed of using  struct utsname\n");
    }
}

void ModuleKernel::refreshData()
{
    return;
}

struct utsname ModuleKernel::getData() const { return this->uts; }
