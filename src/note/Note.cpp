
#ifndef SCREEN
#define SCREEN

#include <bits/stdc++.h>
#include "../../include/note/Note.h"

Note::Note(std::string message)
{
    this->message = message;
}

std::string Note::printNote()
{
    return this->message;
}

#endif