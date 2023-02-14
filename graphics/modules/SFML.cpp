/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** SFML.cpp
*/

#include "include/SFML.hpp"

#define WINDOW_SIZE_X 2000
#define WINDOW_SIZE_Y 2000

// Default values
#define TITLE_FONT_SIZE 40
#define FONT_SIZE 30
#define FONT_SIZE_LITTLE 20
#define COLOR_DARK_GRAY {sf::Color (43, 36, 36)}
#define COLOR_GRAY {sf::Color (128, 128, 128)}
#define COLOR_LIGHT_GRAY {sf::Color (211, 211, 211)}
#define COLOR_SEA_BLUE {sf::Color (0, 128, 128)}
#define COLOR_BLACK {sf::Color::Black}
#define COLOR_WHITE {sf::Color::White}
#define COLOR_GREEN {sf::Color::Green}
#define COLOR_RED {sf::Color::Red}

// Blocks
#define SYSTEM_INFOS_POS {50, 50}
#define SYSTEM_INFOS_SIZE {925, 800}

#define CPU_INFOS_POS {1025, 50}
#define CPU_INFOS_SIZE {925, 800}

#define RAM_INFOS_POS {50, 900}
#define RAM_INFOS_SIZE {925, 300}

#define NETWORK_INFOS_POS {1025, 900}
#define NETWORK_INFOS_SIZE {925, 300}

#define PROCESS_INFOS_POS {50, 1250}
#define PROCESS_INFOS_SIZE {1900, 700}

// Texts
#define SYSTEM_INFOS_TITLE_POS {65, 60}
#define CPU_INFOS_TITLE_POS {1040, 60}
#define RAM_INFOS_TITLE_POS {65, 910}
#define NETWORK_INFOS_TITLE_POS {1040, 910}
#define PROCESS_INFOS_TITLE_POS {65, 1260}

#define HOSTNAME_POS {65, 140}
#define USERNAME_POS {65, 200}
#define DATE_POS {65, 260}
#define TIME_POS {65, 320}
#define KERNEL_POS_X 65
#define KERNEL_POS_Y 380
#define KERNEL_GAP 60

#define CPU_CORE_USAGE_POS_X 1040
#define CPU_CORE_USAGE_POS_Y 140
#define CPU_CORE_USAGE_PB_POS_X 1275
#define CPU_CORE_USAGE_PB_POS_Y 140
#define CPU_CORE_USAGE_PB_WIDTH 650
#define CPU_CORE_GAP 50
#define MAX_SIZE 30

#define RAM_USAGE_POS {65, 940}
#define RAM_INITAL_POS_X 65
#define RAM_INITAL_POS_Y 980
#define RAM_GAP 35

#define NETWORK_USAGE_POS {1040, 940}
#define NETWORK_INITAL_POS_X 1040
#define NETWORK_INITAL_POS_Y 980
#define NETWORK_GAP 35

SFML::SFML()
{
    m_core.getCpu().refreshData();
    this->_window = createWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Rush3");
    this->_lightFont = initFont("graphics/assets/fonts/light.otf");
    this->_regularFont = initFont("graphics/assets/fonts/regular.otf");
    this->_boldFont = initFont("graphics/assets/fonts/bold.otf");

    this->_systemInfos = initRectangleShape(SYSTEM_INFOS_POS, SYSTEM_INFOS_SIZE, COLOR_DARK_GRAY, COLOR_DARK_GRAY, 5);
    this->_cpuInfos = initRectangleShape(CPU_INFOS_POS, CPU_INFOS_SIZE, COLOR_DARK_GRAY, COLOR_DARK_GRAY, 5);
    this->_ramInfos = initRectangleShape(RAM_INFOS_POS, RAM_INFOS_SIZE, COLOR_DARK_GRAY, COLOR_DARK_GRAY, 5);
    this->_networkInfos = initRectangleShape(NETWORK_INFOS_POS, NETWORK_INFOS_SIZE, COLOR_DARK_GRAY, COLOR_DARK_GRAY, 5);
    this->_processInfos = initRectangleShape(PROCESS_INFOS_POS, PROCESS_INFOS_SIZE, COLOR_DARK_GRAY, COLOR_DARK_GRAY, 5);

    this->_systemInfosTitle = initText("System Infos", this->_boldFont, TITLE_FONT_SIZE, COLOR_SEA_BLUE, SYSTEM_INFOS_TITLE_POS);
    this->_cpuInfosTitle = initText("CPU Infos", this->_boldFont, TITLE_FONT_SIZE, COLOR_SEA_BLUE, CPU_INFOS_TITLE_POS);
    this->_ramInfosTitle = initText("RAM Infos", this->_boldFont, TITLE_FONT_SIZE, COLOR_SEA_BLUE, RAM_INFOS_TITLE_POS);
    this->_networkInfosTitle = initText("Network Infos", this->_boldFont, TITLE_FONT_SIZE, COLOR_SEA_BLUE, NETWORK_INFOS_TITLE_POS);
    this->_processInfosTitle = initText("Process Infos", this->_boldFont, TITLE_FONT_SIZE, COLOR_SEA_BLUE, PROCESS_INFOS_TITLE_POS);

    this->_hostnameUsernameText.push_back(initText("Hostname: ", this->_regularFont, FONT_SIZE, COLOR_GRAY, HOSTNAME_POS));
    this->_hostnameUsernameText.push_back(initText("Username: ", this->_regularFont, FONT_SIZE, COLOR_GRAY, USERNAME_POS));
    for (int i = 0; i < 6; i++)
        this->_kernelTexts.push_back(initText("", this->_regularFont, FONT_SIZE, COLOR_GRAY, initVector2f(KERNEL_POS_X, KERNEL_POS_Y + (i * KERNEL_GAP))));
    this->_dateHoursText.push_back(initText("Date: ", this->_regularFont, FONT_SIZE, COLOR_GRAY, DATE_POS));
    this->_dateHoursText.push_back(initText("Hours: ", this->_regularFont, FONT_SIZE, COLOR_GRAY, TIME_POS));

    for (int i = 0; i < this->m_core.getCpu().getCoreFrequency().size(); i++) {
        sf::Vector2f pos = initVector2f(CPU_CORE_USAGE_PB_POS_X, CPU_CORE_USAGE_PB_POS_Y + (i * CPU_CORE_GAP));
        sf::Vector2f size = initVector2f(CPU_CORE_USAGE_PB_WIDTH, FONT_SIZE);
        ProgressBar progressBar(pos, size, 5000, COLOR_GREEN, COLOR_SEA_BLUE);
        this->_cpuCoreTexts.push_back(initText("Core " + std::to_string(i) + ": ", this->_regularFont, FONT_SIZE, COLOR_GRAY, initVector2f(CPU_CORE_USAGE_POS_X, CPU_CORE_USAGE_POS_Y + (i * CPU_CORE_GAP))));
        this->_cpuProgressBar.push_back(progressBar);
    }

    for (int i = 0; i < 6; i++)
        this->_ramDataText.push_back(initText("Ram " + std::to_string(i) + ": ", this->_regularFont, FONT_SIZE, COLOR_GRAY, initVector2f(RAM_INITAL_POS_X, RAM_INITAL_POS_Y + (i * RAM_GAP))));

    for (int i = 0; i < 5; i++)
        this->_networkDataText.push_back(initText("Network " + std::to_string(i) + ": ", this->_regularFont, FONT_SIZE, COLOR_GRAY, initVector2f(NETWORK_INITAL_POS_X, NETWORK_INITAL_POS_Y + (i * NETWORK_GAP))));
}

Core &SFML::getCore() {return this->m_core;}

std::unique_ptr<sf::RenderWindow> &SFML::getWindow(){return this->_window;}

void SFML::handleKeyEvent(sf::Event& event)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Escape:
        case sf::Keyboard::Q:
            this->_window->close();
            break;
        case sf::Keyboard::S:
            // this->_isCpuInfosActive = !this->_isCpuInfosActive;
            // A faire ici switch
            break;
        default:
            break;
    }
}

void SFML::handleEvents()
{
    sf::Event event;

    while (this->_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_window->close();
                break;
            case sf::Event::KeyPressed:
                this->handleKeyEvent(event);
                break;
            default:
                break;
        }
    }
}

void SFML::setValues()
{
    this->_hostnameUsernameText.front().setString("Hostname: " + this->m_core.getHost().getData());
    this->_hostnameUsernameText.back().setString("Username: " + this->m_core.getUser().getData());
    utsname data = this->m_core.getKernel().getData();
    this->_kernelTexts[0].setString("Domain name: " + std::string(data.domainname));
    this->_kernelTexts[1].setString("Machine: " + std::string(data.machine));
    this->_kernelTexts[2].setString("Kernel name: " + std::string(data.nodename));
    this->_kernelTexts[3].setString("Kernel release: " + std::string(data.release));
    this->_kernelTexts[4].setString("Kernel system: " + std::string(data.sysname));
    this->_kernelTexts[5].setString("Kernel version: " + std::string(data.version));

    int coreIdx = 0;
    int nbCores = this->m_core.getCpu().getCoreFrequency().size();
    for (double a : this->m_core.getCpu().getCoreFrequency()) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << a;
        this->_cpuCoreTexts[coreIdx].setString("Core " + std::to_string(coreIdx) + ": " + ss.str());
        this->_cpuProgressBar[coreIdx].setProgress(a);
        coreIdx++;
    }
    this->_dateHoursText.front().setString("Date: " + this->m_core.getDate().getData()["date"]);
    this->_dateHoursText.back().setString("Time: " + this->m_core.getDate().getData()["time"]);

    std::string ramInMb = this->m_core.getRam().getData()["MemTotal"];
    ramInMb = std::to_string((int)(std::stod(ramInMb) / 1000));
    this->_ramDataText[0].setString("Total Ram: " + ramInMb + "MB");

    ramInMb = this->m_core.getRam().getData()["MemFree"];
    ramInMb = std::to_string((int)(std::stod(ramInMb) / 1000));
    this->_ramDataText[1].setString("Free Ram: " + ramInMb + "MB");

    ramInMb = this->m_core.getRam().getData()["MemAvailable"];
    ramInMb = std::to_string((int)(std::stod(ramInMb) / 1000));
    this->_ramDataText[2].setString("Available Ram: " + ramInMb + "MB");

    ramInMb = this->m_core.getRam().getData()["SwapTotal"];
    ramInMb = std::to_string((int)(std::stod(ramInMb) / 1000));
    this->_ramDataText[3].setString("Swap Total: " + ramInMb + "MB");

    ramInMb = this->m_core.getRam().getData()["SwapFree"];
    ramInMb = std::to_string((int)(std::stod(ramInMb) / 1000));
    this->_ramDataText[4].setString("Swap Free: " + ramInMb + "MB");

    ramInMb = this->m_core.getRam().getData()["SwapCached"];
    ramInMb = std::to_string((int)(std::stod(ramInMb) / 1000));
    this->_ramDataText[5].setString("Swap Cached: " + ramInMb + "MB");

    for (std::map<std::string, std::string> i: this->m_core.getNetwork().getData()) {
        this->_networkDataText[0].setString("Name: " + i["name"]);
        this->_networkDataText[1].setString("Rx Bytes: " + i["rx_bytes"]);
        this->_networkDataText[2].setString("Tx Bytes: " + i["tx_bytes"]);
        this->_networkDataText[3].setString("Rx Packets: " + i["rx_packets"]);
        this->_networkDataText[4].setString("Tx Packets: " + i["tx_packets"]);
    }
}

void SFML::display()
{
    this->_window->clear();
    if (this->m_core.getKernel().isActive())
        this->displaySystemInfos();
    if (this->m_core.getCpu().isActive())
        this->displayCpuInfos();
    if (this->m_core.getRam().isActive())
        this->displayRamInfos();
    if (this->m_core.getNetwork().isActive())
        this->displayNetworkInfos();
    this->displayProcessInfos();
    this->_window->display();
}

void SFML::displaySystemInfos()
{
    this->_window->draw(this->_systemInfos);
    this->_window->draw(this->_systemInfosTitle);
    for (auto &text : this->_hostnameUsernameText)
        this->_window->draw(text);
    this->_window->draw(this->_dateHoursText.front());
    this->_window->draw(this->_dateHoursText.back());
    for (sf::Text &text : this->_kernelTexts)
        this->_window->draw(text);
}

void SFML::displayCpuInfos()
{
    this->_window->draw(this->_cpuInfos);
    this->_window->draw(this->_cpuInfosTitle);
    for (sf::Text text : this->_cpuCoreTexts)
        this->_window->draw(text);
    for (ProgressBar &bar : this->_cpuProgressBar) {
        this->_window->draw(bar.getBackground());
        this->_window->draw(bar.getBar());
    }
}

void SFML::displayRamInfos()
{
    this->_window->draw(this->_ramInfos);
    this->_window->draw(this->_ramInfosTitle);
    for (sf::Text text : this->_ramDataText)
        this->_window->draw(text);
}

void SFML::displayNetworkInfos()
{
    this->_window->draw(this->_networkInfos);
    this->_window->draw(this->_networkInfosTitle);
    for (sf::Text text : this->_networkDataText)
        this->_window->draw(text);
}

void SFML::displayProcessInfos()
{
    this->_window->draw(this->_processInfos);
    this->_window->draw(this->_processInfosTitle);
}

SFML::~SFML()
{
    this->_window->close();
}
