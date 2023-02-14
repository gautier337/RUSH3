/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** NCurses.hpp
*/

#pragma once
#include "IMonitorDisplay.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <list>
#include <map>
#include "../../../modules/Core.hpp"

class NCurses : public IMonitorDisplay {
    public:
        NCurses();
        ~NCurses();
        void handleEvents();
        void display();
        void displayHost();
        void displayUser();
        void displayDate();
        void displayCpuInfos();
        void displayRamInfos();
        void displayNetworkInfos();
        void displayKernel();
        void displayPid();
        Core &getCore();
    protected:
        Core m_core;
};
