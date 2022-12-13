
#ifndef MAIN_VIEW_H
#define AIN_VIEW_H

#include <bits/stdc++.h>
#include "./MainScreen.h"
#include "../note/Note.h"
#include "../file/File.h"

class MainView
{
public:
    MainView(){};
    void display();    
private:
    File file = File("notes.txt");
    std::vector<std::string> commands = {"Add", "Delete", "Quit"};
    std::vector<std::string> back = {"Back - b"};
    int inputedCommand(int command, MainScreen view,std::vector<Note> notes,std::vector<std::string> commands);
    int handleDelete(int index, std::vector<Note> &notes);
    void handleExit();
};






#endif