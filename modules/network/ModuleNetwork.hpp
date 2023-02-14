/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleNetwork
*/

#ifndef MODULENETWORK_HPP_
#define MODULENETWORK_HPP_

#include <map>
#include <regex>
#include "../AModule.hpp"
#include <list>

class ModuleNetwork : public AModule {
    public:
        ModuleNetwork() = default;
        ~ModuleNetwork() = default;
        void refreshData() final;
        std::list<std::map<std::string, std::string>> getData() const;

    private:
        std::list<std::map<std::string, std::string>> data_;
};

#endif /* !MODULENETWORK_HPP_ */
