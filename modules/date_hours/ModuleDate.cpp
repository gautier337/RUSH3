/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleDate
*/

#include "ModuleDate.hpp"
#include <iterator>
#include <regex>

ModuleDate::ModuleDate()
    : file_("/proc/driver/rtc"), file_Uptime("/proc/uptime")
{
}

void ModuleDate::convert_to_Date(const std::string &save)
{
    double uptime = std::stod(save);
    int hours = (int)(uptime / 3600);
    int minutes = (int)((uptime - hours * 3600) / 60);
    int seconds = (int)(uptime - hours * 3600 - minutes * 60);
    this->upTime[0] = hours;
    this->upTime[1] = minutes;
    this->upTime[2] = seconds;
}

void ModuleDate::refreshData()
{
    if (!_active)
        return;
    std::string content = this->file_.getContent();
    std::string content_upTime = this->file_Uptime.getContent();
    std::string save;
    std::regex reg("rtc_([a-z]+)\t+: +([0-9]+[:|-][0-9]+[:|-][0-9]+)");
    std::sregex_iterator begin(content.begin(), content.end(), reg);
    std::sregex_iterator end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        this->data_[match[1].str()] = match[2].str();
    }
    save = content_upTime.substr(0, content_upTime.find(" "));
    convert_to_Date(save);
}

std::map<std::string, std::string> ModuleDate::getData() const { return this->data_; }

std::array<int, 3> ModuleDate::getUpTime() const
{
    return this->upTime;
}
