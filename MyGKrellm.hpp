/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** MyGKrellm
*/

#pragma once

#include "./modules/Core.hpp"
#include "graphics/modules/include/IMonitorDisplay.hpp"
#include "graphics/modules/include/NCurses.hpp"
#include "graphics/modules/include/SFML.hpp"
#include "modules/network/ModuleNetwork.hpp"

class MyGKrellm {
    public:
        MyGKrellm() = default;
        ~MyGKrellm() = default;
        bool check(char **argv);
        int launchNcurse();
        int launch();
    protected:
    private:
        bool mode_{false};
};
