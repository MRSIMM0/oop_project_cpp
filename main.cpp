#include <bits/stdc++.h>

#include "./Note.h"
#include "./gui/MainView.h"


std::string strikethrough(const std::string &text)
{
    std::string result;
    for (auto ch : text)
    {
        result.append(u8"\u0336");
        result.push_back(ch);
    }
    return result;
}

int main()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    Note notes[5] = {Note("test"), Note("test2"), Note("test3"), Note("test5"), Note("test")};
    std::string commands[4] = {"Add", "Delete", "Done", "Quit"};


    MainView view(w.ws_col, w.ws_row, 5, notes,4,commands);
    system("clear");
   view.printMainView();

}