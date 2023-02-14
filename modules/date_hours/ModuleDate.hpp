/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleDate
*/

#ifndef MODULEDATE_HPP_
#define MODULEDATE_HPP_

#include "../AModule.hpp"
#include <map>
#include <iomanip>
#include <sstream>
#include <array>

class ModuleDate : public AModule {
  public:
    ModuleDate();
    ~ModuleDate() = default;
    void refreshData() final;
    std::array<int, 3> getUpTime() const;
    void convert_to_Date(const std::string &save);
    std::map<std::string, std::string> getData() const;

  private:
    File file_;
    File file_Uptime;
    std::map<std::string, std::string> data_;
    std::array<int, 3> upTime;
};
#endif /* !MODULEDATE_HPP_ */
