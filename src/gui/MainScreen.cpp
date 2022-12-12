#ifndef MAINSCREEN
#define MAINSCREEN

#include <bits/stdc++.h>
#include "../../include/gui/MainScreen.h"
#include "../../include/note/Note.h"



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