#ifndef MAIN_VIEW_H
#define AIN_VIEW_H

#include <bits/stdc++.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "Screen.h"
#include "Note.h"

class MainView : public Screen
{

private:
    int notes_size;
    Note *notes;
    int commands_size;
    std::string *commands;

public:
    MainView(int cols, int rows, int notes_size, Note *notes, int commands_size,
             std::string *commands) : Screen(cols, rows)
    {
        this->notes_size = notes_size;

        this->notes = notes;

        this->commands_size = commands_size;

        this->commands = commands;
    }

    std::string printTasks();
    void printMainView();
};

std::string MainView::printTasks()
{

    std::string result = "";

    for (int i = 0; i < this->notes_size; i++)
    {
        result = result + tab(std::to_string(i + 1) + " " + this->notes[i].printNote(), 4, " ") + "\n";
    }
    return result;
}

void MainView::printMainView()
{

    std::cout << center("TODO", "-");

    std::string tasks = printTasks();

    int lines = 0;

    for (int i = 0; i < tasks.length(); i++)
    {
        if (tasks[i] == '\n')
        {
            lines++;
        }
    }

    int spacer = ((rows - 2) - (2 * lines)) / 2;

    for (int i = 0; i < spacer; i++)
    {

        tasks = "\n" + tasks + "\n";
    }
    std::cout << tasks;

    std::string t;



    std::cout << createFooter(commands, commands_size, 4) << std::endl
              << "Command:";
    std::cin >> t;
}

#endif