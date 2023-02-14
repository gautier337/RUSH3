/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** AModuleX
*/

#ifndef AMODULEX_HPP_
#define AMODULEX_HPP_

#include "../tools/FileHandler.hpp"
#include "IMonitorModule.hpp"
#include <list>

class AModule : public IMonitorModule {
  public:
    std::string getName() final;
    std::string getTitle() final;
    bool isActive() final;
    void setActive(bool state) final;

  protected:
    std::string _name;
    std::string _title;
    bool _active { true };
};

#endif /* !AMODULEX_HPP_ */
