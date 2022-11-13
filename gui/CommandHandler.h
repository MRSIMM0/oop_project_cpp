#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <bits/stdc++.h>

class CommandHandler
{

public:
    std::string *commands;
    ~CommandHandler(){};
    CommandHandler(std::string *commands)
    {
        this->commands = commands;
    }

public:
    virtual void handle(int command) = 0;
};

#endif