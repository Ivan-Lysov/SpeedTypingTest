#include "TypingTest.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "window.h"

using namespace std;

int TypingTest::timeSpan(int& starting_time) {
    int current_time = time(0);
    int minute = 0;
    int second = current_time - starting_time;
    if (second > 60) {
        minute++;
        starting_time = time(0);
    }
    cout << "Your time: " << minute << " minutes and " << second << " seconds";
    return ((minute * 60) + second);
}

void TypingTest::calculation(char*& str, char current_word, int& total_letters, int& total_words) {
    if (current_word != 8) {
        char* temp = new char[total_letters + 1];
        for (int i = 0; str[i] != '\0'; i++) {
            temp[i] = str[i];
        }
        temp[total_letters - 1] = current_word;
        temp[total_letters] = '\0';
        delete[] str;
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
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i - 1] != 32 && str[i] == 32) {
            total_words++;
        }
    }
}

void TypingTest::display(char& curr_word, char*& str, int& total_letters, int& starting_time, const string& userName) {
    window_cl window;
    int totalWords = 0;
    int wrongs = 0;
    int answer = 0;
    string RandStr;

    cout << "Press 1 for 50 characters, 2 for 100 characters, 3 for 150 characters: ";
    answer = _getch();  

    switch (answer) {
    case '1':
        RandStr = GenerateRandomString(50);
        break;
    case '2':
        RandStr = GenerateRandomString(100);
        break;
    case '3':
        RandStr = GenerateRandomString(150);
        break;
    default:
        cout << "Invalid choice. Exiting..." << endl;
        return;
    }

    cout << "Generated Random String: " << RandStr << endl;
    for (size_t i = 0; i < RandStr.length(); ++i) {
        curr_word = _getch();
        if (RandStr[i] != curr_word) {
            wrongs++;
        }
        if ((curr_word >= 32 && curr_word <= 126) || curr_word == 13 || curr_word == 8) {
            calculation(str, curr_word, total_letters, totalWords);
            system("cls");
            window.homescreen(userName);

            cout << "Generated Random String: " << RandStr << endl;
            cout << "\n\nTotal Letters = " << total_letters - 1 << endl;
            cout << "\n\nTotal Words = " << totalWords << endl;
            cout << "Total Wrong Entries = " << wrongs << endl;
            timeSpan(starting_time);
            window.space();
            for (int j = 0; str[j] != '\0'; j++) {
                cout << str[j];
            }
            window.space();
            cout << "To END THE PROGRAM: PRESS ENTER-KEY" << endl;
        }
        if (curr_word == 13) {
            window.userStatics(totalWords, total_letters, timeSpan(starting_time), userName,wrongs);
        }
    }
    window.userStatics(totalWords, total_letters, timeSpan(starting_time), userName,wrongs);


}

string TypingTest::GenerateRandomString(int len) {
    const char charset[] = " dfabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int charset_size = sizeof(charset) - 1;
    string RandomString;

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < len; i++) {
        RandomString += charset[rand() % charset_size];
    }
    return RandomString;
}
