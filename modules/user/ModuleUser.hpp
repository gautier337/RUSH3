/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleUser
*/

#ifndef MODULEUSER_HPP_
#define MODULEUSER_HPP_

#include "../AModule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class ModuleUser : public AModule {
    public:
        ModuleUser();
        ~ModuleUser() = default;
        void refreshData() final;
        std::string getData() const;
    private:
        std::string UserName_ { "No user" };
};

#endif /* !MODULEUSER_HPP_ */
