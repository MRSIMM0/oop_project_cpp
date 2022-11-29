#ifndef SCREEN_H
#define SCREEN_H
#include <bits/stdc++.h>

/*
Abstract class for console gui
*/

class Screen
{

protected:
    int cols;
    int rows;

public:
    Screen(int cols, int rows);
    std::string center(std::string title, std::string separator);
    std::string tab(std::string title, int tab, std::string sep);
    std::string createFooter(std::vector<std::string> commands, int space);
};

Screen::Screen(int cols, int rows)
{
    this->cols = cols;
    this->rows = rows;
}

/*
Method used to center content
*/
std::string Screen::center(std::string title, std::string separator)
{

    std::string result = title;

    int spacer = (this->cols - title.length()) / 2;
    for (int i = 0; i < spacer; i++)
    {
        result = separator + result + separator;
    }

    return result;
}
/*
Method used to display inforamtion (title) witch given spacing (tab) and given spearator (sep)
*/
std::string Screen::tab(std::string title, int tab, std::string sep)
{

    std::string result = title;

    for (int i = 0; i < tab; i++)
    {
        result = sep + result;
    }

    int spacer = (this->cols - title.length());
    for (int i = 0; i < spacer; i++)
    {
        result = result + sep;
    }

    return (result);
}
/*
Method used to display page footer (commands) with spacing
*/
std::string Screen::createFooter(std::vector<std::string> commands, int space)
{

    int len = commands.size();

    std::string result = "";

    for (int i = 0; i < space; i++)
    {
        result = "-" + result;
    }

    for (int j = 0; j < len; j++)
    {

        result = result + " " + std::to_string(j + 1) + ":" + commands[j] + " ";
        for (int k = 0; k < space; k++)
        {
            result = result + "-";
        }
    }

    int spacer = (this->cols - result.length());
    for (int i = 0; i < spacer; i++)
    {
        result = result + "-";
    }
    return result;
}

#endif