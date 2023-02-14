/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleUser
*/

#include "ModuleHost.hpp"

ModuleHost::ModuleHost() : file_("/proc/sys/kernel/hostname")
{
    this->hostName_ = this->file_.getContent();
}

void ModuleHost::refreshData() {
    return;
}

std::string ModuleHost::getData() const
{
    return this->hostName_;
}
