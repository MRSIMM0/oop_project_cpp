#ifndef MAIN_SCREEN_H
#define AIN_VIEW_H

#include <bits/stdc++.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "Screen.h"
#include "../Note.h"

class MainScreen : public Screen
{

private:
    std::vector<Note> notes;
    std::vector<std::string> commands;

public:
    MainScreen(int cols, int rows, std::vector<Note> notes,
             std::vector<std::string> commands) : Screen(cols, rows)
    {

        this->notes = notes;

        this->commands = commands;
    }

    std::string printTasks();
    void createFooter();
};

std::string MainScreen::printTasks()
{

    std::string result = "";

    for (int i = 0; i < this->notes.size(); i++)
    {
        result = result + tab(std::to_string(i + 1) + " " + this->notes[i].printNote(), 4, " ") + "\n";
    }

    return result;
}

void MainScreen::createFooter()
{
    std::cout << Screen::createFooter(commands, 4);
}

#endif