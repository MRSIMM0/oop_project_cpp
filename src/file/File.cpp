#ifndef FILE
#define FILE

#include "../../include/file/File.h"
#include "../../include/note/Note.h"

#include <bits/stdc++.h>

File::File(std::string fileName)
{
    this->fileName = fileName;
}

void File::save(std::vector<Note> notes)
{
    std::fstream ofs;
    ofs.open(fileName, std::ios::out | std::ios::trunc);
    for (int i = 0; i < notes.size(); i++)
    {
        ofs << notes[i].printNote().append("\n");
    }
    ofs.close();
};

std::vector<Note> File::savedNotes()
{
    std::ifstream MyReadFile(fileName);
    std::string myText;

    std::vector<Note> result;

    while (std::getline(MyReadFile, myText))
    {
        // Output the text from the file
        result.push_back(Note(myText));
    }

    // Close the file
    MyReadFile.close();

    return result;
}

#endif