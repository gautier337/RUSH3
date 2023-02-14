/*
** EPITECH PROJECT, 2023
** Text default functions
** File description:
** Text.cpp
*/

#include "include/sfml.hpp"
#include <iostream>

sf::Font initFont(std::string fontPath)
{
    sf::Font font;

    if (!font.loadFromFile(fontPath))
        exit(EXIT_FAILURE);
    return font;
}

sf::Text initText(std::string str, sf::Font &font, int size, sf::Color color, sf::Vector2f position)
{
    sf::Text text(str, font);

    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    return text;
}
