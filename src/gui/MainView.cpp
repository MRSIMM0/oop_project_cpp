#ifndef MAINVIEW
#define MAINVIEW


#include <bits/stdc++.h>
#include <sys/ioctl.h>

#include "../../include/gui/MainView.h"
#include "../note/Note.cpp"
#include "../file/File.cpp"
#include "MainScreen.cpp"


void MainView::handleExit()
{
    system("clear");
    exit(0);
}

int MainView::handleDelete(int index, std::vector<Note> &notes)
{
    if (index < notes.size())
    {
        notes.erase(notes.begin() + index);
        return -1;
    }
    return -2;
}

int MainView::inputedCommand(int command, MainScreen view, std::vector<Note> notes, std::vector<std::string> commands)
{

    std::string t;

    switch (command)
    {
    case -2:
        std::cout << "Invalid Argument:";
        break;
    case -1:
        std::cout << "Command:";
        break;
    default:
        if (command > commands.size())
        {
            return -2;
        }
        std::cout << commands[command - 1] << ":";
        break;
    }

    std::cin >> t;

    try
    {
        int number = stoi(t);
        if (command == -1)
        {

            switch (number)
            {
            case 3:
                handleExit();
                break;
            default:
                break;
            }
        }
        if (command == 2)
        {
            int exitcode = handleDelete(number - 1, notes);
            file.save(notes);
            return exitcode;
        }

        return number;
    }
    catch (std::invalid_argument ex)
    {
        if (t == "b")
        {
            return -1;
        }

        if (command == 1)
        {
            notes.push_back(Note(t));
            file.save(notes);
        }
        else
        {
            return -2;
        }

        return -1;
    }
}

void MainView::display()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::vector<std::string> currentCommands;
    std::vector<std::string> commands = {"Add", "Delete", "Quit"};
    std::vector<std::string> back = {"Back - b"};
    system("clear");

    int com = -1;

    while (1)
    {
        std::vector<Note> notes = file.savedNotes();
        if (com == -1)
        {
            currentCommands = commands;
        }
        else
        {
            currentCommands = back;
        }

        MainScreen view(w.ws_col, w.ws_row, notes, currentCommands);

        system("clear");

        std::cout << view.center("TODO", "-");

        std::string tasks = view.printedTasks();

        int lines = 0;

        for (int i = 0; i < tasks.length(); i++)
        {
            if (tasks[i] == '\n')
            {
                lines++;
            }
        }

        int spacer = ((w.ws_row - 2) - (2 * lines)) / 2;

        for (int i = 0; i < spacer; i++)
        {
            tasks = "\n" + tasks + "\n";
        }

        std::cout << tasks;
        view.createFooter();
        com = inputedCommand(com, view, notes, commands);
    }
}

#endif