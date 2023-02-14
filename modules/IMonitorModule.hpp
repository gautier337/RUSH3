/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <iostream>

class IMonitorModule {
  public:
    virtual ~IMonitorModule() = default;
    virtual std::string getName() = 0;
    virtual std::string getTitle() = 0;
    virtual bool isActive() = 0;
    virtual void setActive(bool state) = 0;
    virtual void refreshData() = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
