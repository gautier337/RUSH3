/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** IMonitorDisplay.hpp
*/

#pragma once

class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() = default;
        virtual void display() = 0;
        virtual void handleEvents() = 0;
};
