/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** Core
*/

#include "Core.hpp"

ModuleCpu &Core::getCpu() {return cpu_;}

ModuleRam &Core::getRam() {return ram_;}

ModuleUser &Core::getUser() {return user_;}

ModuleKernel &Core::getKernel() {return kernel_;}

ModuleNetwork &Core::getNetwork() {return network_;}

ModuleHost &Core::getHost() {return host_;}

ModuleDate &Core::getDate() {return date_;}

ModulePid &Core::getPid() {return pid_;}

void Core::refresh()
{
    cpu_.refreshData();
    ram_.refreshData();
    user_.refreshData();
    kernel_.refreshData();
    network_.refreshData();
    host_.refreshData();
    date_.refreshData();
    pid_.refreshData();
}
