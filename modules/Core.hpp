/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "kernel/ModuleKernel.hpp"
#include "network/ModuleNetwork.hpp"
#include "ram/ModuleRam.hpp"
#include "user/ModuleUser.hpp"
#include "date_hours/ModuleDate.hpp"
#include "host/ModuleHost.hpp"
#include "pid/ModulePid.hpp"
#include "processor/ModuleCpu.hpp"

class Core {
  public:
    Core() = default;
    ~Core() = default;
    ModuleCpu& getCpu();
    ModuleRam& getRam();
    ModuleUser& getUser();
    ModuleKernel& getKernel();
    ModuleNetwork& getNetwork();
    ModuleHost& getHost();
    ModuleDate& getDate();
    ModulePid& getPid();
    void refresh();

  private:
    ModuleCpu cpu_ {};
    ModuleRam ram_ {};
    ModuleUser user_ {};
    ModuleKernel kernel_ {};
    ModuleNetwork network_ {};
    ModuleHost host_ {};
    ModuleDate date_ {};
    ModulePid pid_ {};
};

#endif /* !CORE_HPP_ */
