/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModulePid
*/

#ifndef MODULEPID_HPP_
#define MODULEPID_HPP_
#include "../AModule.hpp"
#include "dirent.h"
#include <regex>
#include <map>

class ModulePid : public AModule {
  public:
    ModulePid() = default;
    ~ModulePid() = default;
    void refreshData() override;
    void addEntryToPidList(const std::string name);
    std::list<std::map<std::string, std::string>> getData() const;

  private:
    std::list<std::map<std::string, std::string>> pidList_;
};

#endif /* !MODULEPID_HPP_ */
