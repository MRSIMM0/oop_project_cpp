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
    int notes_size;
    Note *notes;
    int commands_size;
    std::string *commands;
    // CommandHandler *handler;

public:
    MainView(int cols, int rows, int notes_size, Note *notes, int commands_size,
             std::string *commands) : Screen(cols, rows)
    {
        // CommandHandler &handler
        this->notes_size = notes_size;

        this->notes = notes;

        this->commands_size = commands_size;

        this->commands = commands;

        // this->handler = &handler;
    }

    std::string printTasks();

    std::string printMainView();
    std::string commandGenerator(int command);
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

std::string MainView::printMainView()
{

    int com = -1;

    while (1){
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

       com = stoi(commandGenerator(com));
    }
}
std::string MainView::commandGenerator(int command)
{
    std::string result[2];



    std::string t;
    if (command == -1)
    {
        std::cout << createFooter(commands, commands_size, 4) << std::endl
                  << "Command:";
        std::cin >> t;
    }else{

        std::string header[] = {"back"};

        std::cout << createFooter(header, 1, 4) << std::endl
                  << commands[command-1]<<":";
        std::cin >> t;        
    }

    // handler->handle(std::atoi(t.c_str()));
    return t;
}
#endif