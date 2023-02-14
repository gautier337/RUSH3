/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** NCurses.cpp
*/

#include "include/NCurses.hpp"

NCurses::NCurses()
{
    initscr();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    noecho();
    cbreak();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_GREEN);
    init_pair(9, COLOR_BLACK, COLOR_YELLOW);
}

void NCurses::display()
{
    attron(COLOR_PAIR(1));
    if (this->m_core.getHost().isActive())
        this->displayHost();
    if (this->m_core.getUser().isActive())
        this->displayUser();
    if (this->m_core.getDate().isActive())
        this->displayDate();
    if (this->m_core.getCpu().isActive())
        this->displayCpuInfos();
    if (this->m_core.getRam().isActive())
        this->displayRamInfos();
    if (this->m_core.getNetwork().isActive())
        this->displayNetworkInfos();
    if (this->m_core.getKernel().isActive())
        this->displayKernel();
    if (this->m_core.getPid().isActive())
        this->displayPid();
    attroff(COLOR_PAIR(1));
}

void NCurses::displayHost() 
{
    attron(COLOR_PAIR(2));
    mvprintw(0, 0, "Hostname: %s", this->m_core.getHost().getData().c_str());
    attroff(COLOR_PAIR(2));
}

void NCurses::displayUser() 
{
    attron(COLOR_PAIR(3));
    mvprintw(1, 0, "Username: %s", this->m_core.getUser().getData().c_str());
    attroff(COLOR_PAIR(3));
}

void NCurses::displayDate()
{
    attron(COLOR_PAIR(4));
    mvprintw(2, 0, "Hours: %s", this->m_core.getDate().getData()["time"].c_str());
    mvprintw(3, 0, "Date: %s", this->m_core.getDate().getData()["date"].c_str());
    mvprintw(4, 0, "Uptime: %dh %dm %ds", this->m_core.getDate().getUpTime()[0], this->m_core.getDate().getUpTime()[1],
        this->m_core.getDate().getUpTime()[2]);
    attroff(COLOR_PAIR(4));
}

void NCurses::displayRamInfos()
{
    attron(COLOR_PAIR(5));
    mvprintw(6, 0, "Total Mem: %s", this->m_core.getRam().getData()["MemTotal"].c_str());
    mvprintw(7, 0, "Free Mem: %s", this->m_core.getRam().getData()["MemFree"].c_str());
    mvprintw(8, 0, "Available Mem: %s", this->m_core.getRam().getData()["MemAvailable"].c_str());
    mvprintw(9, 0, "SwapTotal: %s", this->m_core.getRam().getData()["SwapTotal"].c_str());
    mvprintw(10, 0, "SwapFree: %s", this->m_core.getRam().getData()["SwapFree"].c_str());
    mvprintw(11, 0, "SwapCached: %s", this->m_core.getRam().getData()["SwapCached"].c_str());
    attroff(COLOR_PAIR(5));
}

Core& NCurses::getCore() { return this->m_core; }

void NCurses::displayNetworkInfos()
{
    attron(COLOR_PAIR(6));
    for (std::map<std::string, std::string> i : this->m_core.getNetwork().getData()) {
        mvprintw(13, 0, "name: %s", i["name"].c_str());
        mvprintw(14, 0, "rx_bytes: %s", i["rx_bytes"].c_str());
        mvprintw(15, 0, "tx_bytes: %s", i["tx_bytes"].c_str());
        mvprintw(16, 0, "rx_packets: %s", i["rx_packets"].c_str());
        mvprintw(17, 0, "tx_packets: %s", i["tx_packets"].c_str());
    }
    attroff(COLOR_PAIR(6));
}

void NCurses::displayCpuInfos()
{
    int i = 0;

    attron(COLOR_PAIR(7));
    for (double a : this->m_core.getCpu().getCoreFrequency()) {
        mvprintw(6 + i, 25, "Core %d: %lf", i, a);
        i++;
    }
    attroff(COLOR_PAIR(7));
}

void NCurses::displayKernel()
{
    attron(COLOR_PAIR(8));
    mvprintw(0, 25, "Machine: %s", this->m_core.getKernel().getData().machine);
    mvprintw(1, 25, "Nodename: %s", this->m_core.getKernel().getData().nodename);
    mvprintw(2, 25, "Release: %s", this->m_core.getKernel().getData().release);
    mvprintw(3, 25, "Sysname: %s", this->m_core.getKernel().getData().sysname);
    mvprintw(4, 25, "Version: %s", this->m_core.getKernel().getData().version);
    attroff(COLOR_PAIR(8));
}

void NCurses::displayPid()
{
    int index = 0;

    attron(COLOR_PAIR(9));
    for (std::map<std::string, std::string> i : this->m_core.getPid().getData()) {
        if (index >= 30)
            return;
        mvprintw(
            1 * index, 100, "%s\t%s\t%s\t%s", i["pid"].c_str(), i["name"].c_str(), i["uid"].c_str(), i["cmdline"].c_str());
        index++;
    }
    attroff(COLOR_PAIR(9));
}

void NCurses::handleEvents()
{
    int ch = getch();

    switch (ch) {
    case 'a':
        this->m_core.getKernel().setActive(!(this->m_core.getKernel().isActive()));
        break;
    case 'b':
        this->m_core.getHost().setActive(!(this->m_core.getHost().isActive()));
        break;
    case 'c':
        this->m_core.getUser().setActive(!(this->m_core.getUser().isActive()));
        break;
    case 'z':
        this->m_core.getCpu().setActive(!(this->m_core.getCpu().isActive()));
        break;
    case 'e':
        this->m_core.getRam().setActive(!(this->m_core.getRam().isActive()));
        break;
    case 'r':
        this->m_core.getNetwork().setActive(!(this->m_core.getNetwork().isActive()));
        break;
    case 't':
        this->m_core.getDate().setActive(!(this->m_core.getDate().isActive()));
        break;
    case 'y':
        this->m_core.getDate().setActive(true);
        this->m_core.getUser().setActive(true);
        this->m_core.getHost().setActive(true);
        this->m_core.getNetwork().setActive(true);
        this->m_core.getCpu().setActive(true);
        this->m_core.getRam().setActive(true);
        this->m_core.getKernel().setActive(true);
        break;
    case 'u':
        this->m_core.getDate().setActive(false);
        this->m_core.getUser().setActive(false);
        this->m_core.getHost().setActive(false);
        this->m_core.getNetwork().setActive(false);
        this->m_core.getCpu().setActive(false);
        this->m_core.getRam().setActive(false);
        this->m_core.getKernel().setActive(false);
        break;
    case 'q':
        endwin();
        exit(0);
        break;
    default:
        break;
    }
}

NCurses::~NCurses() { endwin(); }
