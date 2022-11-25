#ifndef MAIN_VIEW_H
#define AIN_VIEW_H

#include <bits/stdc++.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "Screen.h"
#include "../Note.h"
#include "CommandHandler.h"

class MainView : public Screen
{

private:

    std::vector<Note> notes;
    std::vector<std::string> commands;
    // CommandHandler *handler;

public:
    MainView(int cols, int rows, std::vector<Note> notes,
            std::vector<std::string> commands) : Screen(cols, rows)
    {
        // CommandHandler &handler

        this->notes = notes;


        this->commands = commands;

        // this->handler = &handler;
    }

    std::string printTasks();
    void createFooter();
};

std::string MainView::printTasks()
{

    std::string result = "";

    for (int i = 0; i < this->notes.size(); i++)
    {
        result = result + tab(std::to_string(i + 1) + " " + this->notes[i].printNote(), 4, " ") + "\n";
    }

    return result;
}

void MainView::createFooter()
{
   std::cout<<Screen::createFooter(commands, 4);
}

    // handler->handle(std::atoi(t.c_str()));
    //  return -1;

#endif