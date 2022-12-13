#pragma once
#ifndef MAIN_SCREEN_H
#define AIN_VIEW_H

#include <bits/stdc++.h>
#include "Screen.h"
#include "../note/Note.h"

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

    std::string printedTasks();
    void createFooter();
};

#endif