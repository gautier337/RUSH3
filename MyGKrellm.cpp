/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** MyGKrellm
*/

#include "MyGKrellm.hpp"

int MyGKrellm::launchNcurse()
{
    NCurses graphic;
    while (1) {
        clear();
        graphic.getCore().refresh();
        graphic.display();
        graphic.handleEvents();
        refresh();
        sleep(1);
    }
    return 0;
}

int MyGKrellm::launch()
{
    if (mode_ == true)
        return launchNcurse();
    SFML sfml_;
    while (sfml_.getWindow()->isOpen()) {
        clear();
        sfml_.getCore().refresh();
        sfml_.setValues();
        sfml_.display();
        sfml_.handleEvents();
        refresh();
        sleep(1);
    }
    return 0;
}
