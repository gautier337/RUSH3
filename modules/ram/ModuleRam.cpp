/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleRam
*/

#include "ModuleRam.hpp"

ModuleRam::ModuleRam()
    : file_("/proc/meminfo")
{
}

void ModuleRam::refreshData()
{
    if (!_active)
        return;
    std::string content = this->file_.getContent();
    std::regex reg("(Mem[A-z]+): +([0-9]+) kB");
    std::regex reg_swap("(Swap[A-z]+): +([0-9]+) kB");
    std::sregex_iterator begin(content.begin(), content.end(), reg);
    std::sregex_iterator end = std::sregex_iterator();
    std::sregex_iterator begin_swap(content.begin(), content.end(), reg_swap);
    std::sregex_iterator end_swap = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        this->data_[match[1].str()] = match[2].str();
    }
    for (std::sregex_iterator i = begin_swap; i != end_swap; ++i) {
        std::smatch match = *i;
        this->data_[match[1].str()] = match[2].str();
    }
    // std::cout << "Memtotal : " << this->data_["MemTotal"] << std::endl;
    // std::cout << "MemFree : " << this->data_["MemFree"] << std::endl;
    // std::cout << "MemAvaiblable : " << this->data_["MemAvailable"] << std::endl;
    // std::cout << "SwapTotal : " << this->data_["SwapTotal"] << std::endl;
    // std::cout << "SwapFree : " << this->data_["SwapFree"] << std::endl;
    // std::cout << "SwapCached : " << this->data_["SwapCached"] << std::endl;
    return;
}

std::map<std::string, std::string> ModuleRam::getData() const { return this->data_; }
