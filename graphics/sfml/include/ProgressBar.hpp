/*
** EPITECH PROJECT, 2023
** Progress bar default
** File description:
** ProgressBar.hpp
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "sfml.hpp"
#include <iostream>
#include <memory>

class ProgressBar {
    public:
        ProgressBar(sf::Vector2f pos, sf::Vector2f size, int numberOfTicks, sf::Color barColor, sf::Color backgroundColor);
        void setProgress(int progress);
        sf::RectangleShape getBackground() const;
        sf::RectangleShape getBar() const;

    private:
        float m_tickSize;
        sf::RectangleShape m_bar;
        sf::RectangleShape m_background;
};
