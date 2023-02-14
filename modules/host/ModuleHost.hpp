/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleUser
*/

#ifndef MODULEHOST_HPP_
#define MODULEHOST_HPP_

#include "../AModule.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

class ModuleHost : public AModule {
  public:
    ModuleHost();
    ~ModuleHost() = default;
    void refreshData() final;
    std::string getData() const;

  private:
    File file_;
    std::string hostName_ { "No Host" };
};

#endif /* !MODULEHOST_HPP_ */
