/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** AModuleString
*/

#include "AModule.hpp"

std::string AModule::getName() { return this->_name; }

std::string AModule::getTitle() { return this->_title; }

bool AModule::isActive() { return this->_active; }

void AModule::setActive(bool state) { this->_active = state; }
