/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleCpu
*/

#include "ModuleCpu.hpp"

ModuleCpu::ModuleCpu()
    : cpuInfo_("/proc/cpuinfo")
{
    this->parseName();
}

void ModuleCpu::parseName()
{
    std::string content = this->cpuInfo_.getContent();
    std::regex reg("model name\t+: +(.+)");
    std::smatch match;
    std::regex_search(content, match, reg);
    this->modelName_ = match[1].str();
}

std::string ModuleCpu::getModel() const { return this->modelName_; }

void ModuleCpu::parseInfo()
{
    std::string content = this->cpuInfo_.getContent();
    std::regex reg("cpu MHz\t+: +([0-9]+.[0-9]+)");
    std::sregex_iterator begin(content.begin(), content.end(), reg);
    std::sregex_iterator end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        this->coreFrequency_.push_back(stod(match[1].str()));
    }
    return;
}

std::list<double> ModuleCpu::getCoreFrequency() const { return this->coreFrequency_; }

void ModuleCpu::refreshData()
{
    if (!this->_active)
        return;
    this->coreFrequency_.clear();
    this->parseInfo();
}
