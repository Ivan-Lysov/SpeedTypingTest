#include <conio.h>
#include<iostream>
#include <cctype>
#include <string>
#include "windows.h"
#include "window.h"
#include <time.h>

window_cl::window_cl() : name("DefaultName") {}

void window_cl :: space(){
    cout << "\n\n\n";
}

string window_cl::startscreen()
{
    char ch = 1;
    string name;
    space();
    cout << "TYPING SPEED TEST IN C++";
    space();
    cout << "enter your name, pls" << endl;
    cin >> name;
    space();
    system("cls");
    return name;
}

void window_cl::homescreen(string name) {
    cout << "Welcome, " << name;
    space();
    cout << "now, we go to test your speed typing";
    space();
}

int window_cl::UserIntefaceStartScreen(char& current_word, string UserName) {
    homescreen(UserName);
    cout << "Press the special symbol " << endl;
    current_word = _getch();
    current_word = toupper(current_word);
    while (current_word != 'R') {
        if (current_word == '0') {
            cout << "Goodbye";
            exit(0); 
        }
        cout << "Ohh.. please press the correct word" << endl;
        current_word = _getch();
        current_word = toupper(current_word);
    }
    cout << "GO " << endl;
    Sleep(1000);
    system("cls");
    return (time(0));
}
    
void window_cl::userStatics(int total_words, int total_letters, int seconds, const string name, int wrongs) {
    system("cls");
    space();
    cout << "User Statistics: " << endl;
    cout << name << ", here are your statistics: " << endl;
    cout << "Total number of wrongs: " << wrongs << endl;
    cout << "Total number of printed words: " << total_words << endl;
    cout << "Total number of printed letters: " << total_letters << endl;
    cout << "Your Time: " << seconds / 60 << "." << seconds % 60 << " seconds " << endl;
    double minutes = static_cast<double>(seconds) / 60.0; // Приводим секунды к типу double для точного деления
    //if (minutes != 0) {
    //    cout << "Words per minute: " << static_cast<int>(total_words / minutes) << endl; // Округляем до целого числа
    //    cout << "Letters per minute: " << static_cast<int>(total_letters / minutes) << endl; // Округляем до целого числа
    //}
    //else {
    //    cout << "FLASH ^)" << endl; // Если время меньше минуты, выводим сообщение
    //}
}