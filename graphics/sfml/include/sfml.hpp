/*
** EPITECH PROJECT, 2023
** SFML Default functions
** File description:
** Sfml.hpp
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "ProgressBar.hpp"

// Clock
float getElapsedTime(sf::Clock clock);

// Init
sf::IntRect initRect(int x, int y, int width, int height);
sf::Vector2f initVector2f(float x, float y);
sf::Color initColor(int r, int g, int b, int a);


// Shape
sf::RectangleShape initRectangleShape(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color outlineColor, int outlineThickness);
sf::CircleShape initCircleShape(sf::Vector2f position, float radius, sf::Color color, sf::Color outlineColor, int outlineThickness);

// Text
sf::Font initFont(std::string fontPath);
sf::Text initText(std::string str, sf::Font &font, int size, sf::Color color, sf::Vector2f position);

// Window
std::unique_ptr<sf::RenderWindow> createWindow(int width, int height, std::string title, int framerateLimit = 60);
std::unique_ptr<sf::RenderWindow> setWindowIcon(std::unique_ptr<sf::RenderWindow> window, std::string path);
