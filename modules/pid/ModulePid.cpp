/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModulePid
*/

#include "ModulePid.hpp"

void ModulePid::addEntryToPidList(const std::string name)
{
    std::map<std::string, std::string> data;
    std::regex rName("Name:\\s*(.+)");
    std::regex rPid("Pid:\t+([0-9]+)");
    std::regex rUid("Uid:\t+([0-9]\t[0-9]\t[0-9]\t[0-9])");
    std::regex replace("\t");
    std::smatch match;
    File file(("/proc/" + name + "/status"));
    std::string content = file.getContent();
    std::regex_search(content, match, rName);
    data["name"] = match[1];
    std::regex_search(content, match, rPid);
    data["pid"] = match[1];
    std::regex_search(content, match, rUid);
    data["uid"] = match[1];
    data["uid"] = std::regex_replace(data["uid"], replace, "");
    file.open(("/proc/" + name + "/cmdline"));
    data["cmdline"] = file.getContent();
    this->pidList_.push_back(data);
}

void ModulePid::refreshData()
{
    struct dirent* entry = nullptr;
    DIR* dir = opendir("/proc/");
    std::regex r("^[0-9]+$");
    int i = 0;
    if (!_active || !dir)
        return;
    this->pidList_.clear();
    while ((entry = readdir(dir)) != nullptr && i < 30) {
        std::string name(entry->d_name);
        if (entry->d_type != DT_DIR || !std::regex_match(name, r))
            continue;
        this->addEntryToPidList(name);
        i++;
    }
    if (dir)
        closedir(dir);
}

std::list<std::map<std::string, std::string>> ModulePid::getData() const { return this->pidList_; }
