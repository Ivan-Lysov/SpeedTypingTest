#include <conio.h>
#include<iostream>
#include <cctype>
#include "windows.h"
#include <time.h>

using namespace std;

void space()
{
    cout << "\n\n\n";
}

string startscreen()
{
    char ch = 1;
    string name;
    space();
    cout << "TYPING SPEED TEST IN C++";
    space();
    cout << "enter your name, pls\n";
    cin >> name;
    space();
    system("cls");
    return name;
}

void homescreen(string name) {
    cout << "Welcome, " << name;
    space();
    cout << "now, we go to test your speed typing";
    space();
}

int UserIntefaceStartScreen(char& current_word, string UserName) {
    homescreen(UserName);
    cout << "press special simbol \n";
    current_word = _getch();
    current_word = toupper(current_word);
    while (current_word != 'R') {
        if (current_word == '0') {
            cout << "goodbye";
            exit(0); // Exit the program if '0' is pressed
        }
        cout << "Ohh.. please press correct word\n";
        current_word = _getch();
        current_word = toupper(current_word);

    }

    cout << "GO \n"; 
    Sleep(1000);
    system("cls");
    return (time(0));
    
}

void userStatics(int total_words, int total_letters, int seconds, string name) {
    system("cls");
    space();
    cout << "User Statics: \n";
    cout << name << " Your statics, Bro \n";
    cout << "Total number of printed words: " << total_words << "\n";
    cout << "Total number of printed letters: " << total_letters << "\n";
    cout << "Your Time: " << seconds / 60 << "." << seconds % 60 << " seconds \n";
    cout << "Word in minute: " << total_words / (seconds % 60) << "\n";//
    cout << "Letters in minute: " << total_letters / (seconds % 60) << "\n";
}

int time_span(int& starting_time) {
    int current_time = time(0);
    int minute = 0;
    int second = current_time - starting_time;
    if (second > 60) {
        minute++;
        starting_time = time(0);
    }
    cout << "Your time: " << minute << "minutes and " << second << "seconds";
    return ((minute * 60) + second);
}

void calculation(char*& str, const char  current_word, int& total_letters, int& total_words) {
    if (current_word != 8) {
        char* temp = new char[total_letters + 1];
        for (int i = 0; str[i] != '\0'; i++) {
            temp[i] = str[i];
        }
        temp[total_letters - 1] = current_word;
        temp[total_letters] = '\0';
        delete[]str;
        str = temp;
        total_letters++;
    }
    if (current_word == 8 && total_letters != 0) {

        char* temp = new char[total_letters - 1];
        for (int i = 0; i < total_letters - 1; i++) {
            temp[i] = str[i];
        }
        temp[total_letters - 2] = '\n'; 
        delete[] str;
        str = temp;
        total_letters--;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i - 1] != 32 && str[i] == 32)
        {
            total_words++;
        }
    }
}

void display(char& curr_word, char*& str, int& total_letters, int& starting_time, string userName)
{
    do
    {
        int totalWords = 0;
        curr_word = _getch();
        if ((curr_word >= 32 && curr_word <= 126) || curr_word == 13 || curr_word == 8)
        {
            calculation(str, curr_word, total_letters, totalWords);
            system("cls");
            int currentTime = time(0);
            homescreen(userName);
            cout << "\n\nTotal Letters = " << total_letters - 1 << "\n";
            cout << "\n\nTotal Words = " << totalWords << "\n";
            time_span(starting_time);
            space();
            for (int i = 0; str[i] != '\0'; i++)
            {
                cout << str[i];
            }
            space();
            space();
            cout << "To END THE PROGRAM : PRESS ENTER-KEY\n";
        }
        else
        {
            curr_word = _getch();
        }
        if (curr_word == 13)
        {
            userStatics(totalWords, total_letters, time_span(starting_time), userName);
        }
    } while (curr_word != 13);
}

int main()
{
    int total_letters = 1;
    char* str = new char[total_letters] {'\0'};
    char curr_word;
    string userName = startscreen();
    int starting_time = UserIntefaceStartScreen(curr_word, userName);
    display(curr_word, str, total_letters, starting_time, userName);
    delete[] str;
    str = NULL;
    return 0;
}

