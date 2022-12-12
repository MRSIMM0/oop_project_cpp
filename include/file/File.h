#pragma once
#ifndef FILE_H
#define FILE_H
#include <bits/stdc++.h>
#include "../note/Note.h"

class File
{
private:
    std::string fileName;

public:
    void save(std::vector<Note> notes);
    std::vector<Note> savedNotes();
    File(std::string fileName);
};



#endif