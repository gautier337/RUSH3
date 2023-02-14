/*
** EPITECH PROJECT, 2023
** Default progress bar
** File description:
** ProgressBar.cpp
*/

#include "include/ProgressBar.hpp"

ProgressBar::ProgressBar(sf::Vector2f pos, sf::Vector2f size, int numberOfTicks, sf::Color barColor, sf::Color backgroundColor)
{
    this->m_tickSize = size.x / numberOfTicks;
    this->m_bar = initRectangleShape(pos, {0, size.y}, barColor, sf::Color::Transparent, 0);
    this->m_background = initRectangleShape(pos, size, backgroundColor, sf::Color::Transparent, 0);
}

void ProgressBar::setProgress(int progress)
{
    this->m_bar.setSize(initVector2f(progress * this->m_tickSize, this->m_bar.getSize().y));
}

sf::RectangleShape ProgressBar::getBackground() const
{
    return this->m_background;
}

sf::RectangleShape ProgressBar::getBar() const
{
    return this->m_bar;
}
