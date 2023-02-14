/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleNetwork
*/

#include "ModuleNetwork.hpp"
#include "dirent.h"

void ModuleNetwork::refreshData()
{
    struct dirent* entry = nullptr;
    DIR* dir = opendir("/sys/class/net/");
    File file;

    if (!_active || !dir)
        return;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name(entry->d_name);
        std::map<std::string, std::string> node;
        if (entry->d_type != DT_LNK || name[0] == '.')
            continue;
        node["name"] = name;
        file.open("/sys/class/net/" + name + "/statistics/rx_bytes");
        node["rx_bytes"] = file.getContent();
        node["rx_bytes"].pop_back();
        file.open("/sys/class/net/" + name + "/statistics/tx_bytes");
        node["tx_bytes"] = file.getContent();
        node["tx_bytes"].pop_back();
        file.open("/sys/class/net/" + name + "/statistics/rx_packets");
        node["rx_packets"] = file.getContent();
        node["rx_packets"].pop_back();
        file.open("/sys/class/net/" + name + "/statistics/tx_packets");
        node["tx_packets"] = file.getContent();
        node["tx_packets"].pop_back();
        this->data_.push_back(node);
    }
    if (dir)
        closedir(dir);
}

std::list<std::map<std::string, std::string>> ModuleNetwork::getData() const { return this->data_; }
