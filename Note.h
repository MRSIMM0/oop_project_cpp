#ifndef NOTE_H
#define NOTE_H
#include <bits/stdc++.h>
class Note
{

private:
    std::string message;

public:

    Note() = default;
    Note(std::string message)
    {
        this->message = message;
    }

    std::string printNote()
    {
        return this->message;
    }
};

#endif
