/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleCou
*/

#ifndef MODULECPU_HPP_
#define MODULECPU_HPP_

#include "../AModule.hpp"
#include <regex>

class ModuleCpu : public AModule {
  public:
    ModuleCpu();
    ~ModuleCpu() = default;
    void refreshData() override;
    std::list<double> getCoreFrequency() const;
    std::string getModel() const;
    void parseInfo();
    void parseName();

  private:
    std::list<double> coreFrequency_;
    std::string modelName_;
    File cpuInfo_;
};

#endif /* !MODULECPU_HPP_ */
