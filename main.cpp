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
   
}