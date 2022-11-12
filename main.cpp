#include <bits/stdc++.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

class Note
{

private:
    std::string message;

public:
    Note(std::string message)
    {
        this->message = message;
    }

    std::string printNote()
    {
        return this->message;
    }
};

class MainScreen
{
};



std::string center(std::string title, int cols, std::string separator)
{

    std::string result = title;

    int spacer = (cols - title.length()) / 2;
    for (int i = 0; i < spacer; i++)
    {
        result = separator + result + separator;
    }

    return result;
}

std::string tab(std::string title, int tab,std::string sep, int cols){

       
    std::string result = title;

    for(int i =0;i<tab;i++){
        result = sep + result;
    }

    int spacer = (cols - title.length());
    for (int i = 0; i < spacer; i++)
    {
        result =  result + sep;
    }

    return(result);

}

std::string createFooter(std::string commands[], int len, int space, int cols)
{

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

    int spacer = (cols - result.length());
    for (int i = 0; i < spacer; i++)
    {
        result = result + "-";
    }
    return result;
}

std::string strikethrough(const std::string& text) {
  std::string result;
  for (auto ch : text) {
    result.append(u8"\u0336");
    result.push_back(ch);
  }
  return result;
}


std::string printTasks(Note notes[], int size,int cols){

    std::string result = "";

    for (int i = 0; i < size; i++)
    {
        result = result + tab(std::to_string(i+1)+" "+notes[i].printNote(),4," ", cols) + "\n";
    }
    return result;
}



void printMainView(Note notes[], int size)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::cout << center("TODO", w.ws_col,"-");

    std::string tasks = printTasks(notes, size,w.ws_col);


    int lines = 0;

    for(int i = 0; i<tasks.length(); i++){
        if(tasks[i] == '\n'){
            lines++;
        }
    }


    int spacer = ((w.ws_row-2) - (2*lines))/2;


    for(int i = 0;i<spacer;i++){
       
        tasks = "\n"+tasks+"\n";

       
    }
  std::cout<<tasks;
   


    std::string t;

    std::string commands[4] = {"Add", "Delete","Done", "Quit"};

    std::cout << createFooter(commands, 4, 4, w.ws_col) << std::endl
              << "Command:";
    std::cin >> t;
}

int main()
{   

    Note notes[5] = {Note("test"), Note("test2"), Note("test3"), Note("test5"),Note("test")};

    printMainView(notes,4);
    system("clear");
    printMainView(notes,5);
}