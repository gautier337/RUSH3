/*
** EPITECH PROJECT, 2023
** Shape default functions
** File description:
** Shape.cpp
*/

#include "include/sfml.hpp"

sf::RectangleShape initRectangleShape(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color outlineColor, int outlineThickness)
{
    sf::RectangleShape rectangle;

    rectangle.setSize(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(outlineThickness);
    return rectangle;
}

sf::CircleShape initCircleShape(sf::Vector2f position, float radius, sf::Color color, sf::Color outlineColor, int outlineThickness)
{
    sf::CircleShape circle;

    circle.setRadius(radius);
    circle.setFillColor(color);
    circle.setPosition(position);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(outlineThickness);
    return circle;
}
