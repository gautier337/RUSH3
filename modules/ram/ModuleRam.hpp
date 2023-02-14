/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleRam
*/

#ifndef MODULERAM_HPP_
#define MODULERAM_HPP_

#include <map>
#include <regex>
#include "../AModule.hpp"

class ModuleRam : public AModule {
    public:
        ModuleRam();
        ~ModuleRam() = default;
        void refreshData() final;
        std::map<std::string, std::string> getData() const;

    private:
        File file_;
        std::map<std::string, std::string> data_;
};

#endif /* !MODULERAM_HPP_ */
