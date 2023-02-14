/*
** EPITECH PROJECT, 2023
** Init default functions
** File description:
** Init.cpp
*/

#include "include/sfml.hpp"

sf::IntRect initRect(int x, int y, int width, int height)
{
    sf::IntRect rect;

    rect.left = x;
    rect.top = y;
    rect.width = width;
    rect.height = height;
    return rect;
}

sf::Vector2f initVector2f(float x, float y)
{
    sf::Vector2f vector;

    vector.x = x;
    vector.y = y;
    return vector;
}

sf::Color initColor(int r, int g, int b, int a)
{
    sf::Color color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}
