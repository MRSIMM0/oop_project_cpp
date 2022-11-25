#include <bits/stdc++.h>
#include "./Note.h"
#include "./gui/MainView.h"

void handleExit()
{
    system("clear");
    exit(0);
}

void handleAdd(){

};

int handleDelete(int index, std::vector<Note> &notes)
{
    if (index < notes.size())
    {
        notes.erase(notes.begin() + index);
        return -1;
    }

    return -2;
}

int commandGenerator(int command, MainView view, std::vector<Note> &notes, std::vector<std::string> &commands)
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
            return handleDelete(number - 1, notes);
        }

        return number;
    }
    catch (std::invalid_argument ex)
    {   
        if(t == "b"){
            return -1;
        }

        if (command == 1)
        {
            notes.push_back(Note(t));
        }
        else
        {
            return -2;
        }

        return -1;
    }
}
int main()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::vector<Note> notes = {Note("test"), Note("test2"), Note("test3"), Note("test5"), Note("test")};
    std::vector<std::string> currentCommands;
    std::vector<std::string> commands = {"Add", "Delete", "Quit"};
   std::vector<std::string> back = {"Back - b"};
    system("clear");

    int com = -1;

    while (1)
    {
        if(com==-1){
            currentCommands = commands;
        }else{
            currentCommands = back;
        }

        MainView view(w.ws_col, w.ws_row, notes, currentCommands);

        system("clear");

        std::cout << view.center("TODO", "-");

        std::string tasks = view.printTasks();

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
        com = commandGenerator(com, view, notes, commands);
    }
}