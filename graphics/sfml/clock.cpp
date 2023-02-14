/*
** EPITECH PROJECT, 2023
** Clock default functions
** File description:
** Clock.cpp
*/

#include "include/sfml.hpp"

float getElapsedTime(sf::Clock clock)
{
    return clock.getElapsedTime().asSeconds();
}
