/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** SFML.hpp
*/

#pragma once
#include "IMonitorDisplay.hpp"
#include "../../sfml/include/sfml.hpp"
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>
#include <list>
#include <map>
#include "../../../modules/Core.hpp"
#include <sstream>

class SFML : public IMonitorDisplay {
    public:
        SFML();
        ~SFML();
        void handleKeyEvent(sf::Event& event);
        void handleEvents();
        void setValues();
        void display();
        void displaySystemInfos();
        void displayCpuInfos();
        void displayRamInfos();
        void displayNetworkInfos();
        void displayProcessInfos();
        Core &getCore();
        std::unique_ptr<sf::RenderWindow> &getWindow();
    protected:
        Core m_core;

    private:
        std::unique_ptr<sf::RenderWindow> _window;
        sf::Font _lightFont;
        sf::Font _regularFont;
        sf::Font _boldFont;
        sf::RectangleShape _systemInfos;
        sf::RectangleShape _cpuInfos;
        sf::RectangleShape _ramInfos;
        sf::RectangleShape _networkInfos;
        sf::RectangleShape _processInfos;
        sf::Text _systemInfosTitle;
        sf::Text _cpuInfosTitle;
        sf::Text _ramInfosTitle;
        sf::Text _networkInfosTitle;
        sf::Text _processInfosTitle;
        std::vector<sf::Text> _hostnameUsernameText;
        std::vector<sf::Text> _kernelTexts;
        std::vector<sf::Text> _cpuCoreTexts;
        std::vector<sf::Text> _dateHoursText;
        std::vector<sf::Text> _ramDataText;
        std::vector<sf::Text> _networkDataText;
        std::vector<ProgressBar> _cpuProgressBar;
};
