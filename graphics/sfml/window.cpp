/*
** EPITECH PROJECT, 2023
** Window default functions
** File description:
** Window.cpp
*/

#include "include/sfml.hpp"

std::unique_ptr<sf::RenderWindow> createWindow(int width, int height, std::string title, int framerateLimit)
{
    sf::VideoMode videoMode(width, height, 32);
    sf::Uint32 style = sf::Style::Default;
    std::unique_ptr<sf::RenderWindow> window(new sf::RenderWindow(videoMode, title, style));

    window->setFramerateLimit(framerateLimit);
    return window;
}

std::unique_ptr<sf::RenderWindow> setWindowIcon(std::unique_ptr<sf::RenderWindow> window, std::string path)
{
    sf::Image icon;

    if (!icon.loadFromFile(path))
        return window;
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    return window;
}
