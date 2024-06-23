#include "window.h"
#include "TypingTest.h"
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    window_cl window;
    TypingTest typingTest;

    int total_letters = 1;
    char* str = new char[total_letters] {'\0'};
    char curr_word;
    string userName = window.startscreen();
    int starting_time = window.UserIntefaceStartScreen(curr_word, userName);

    cout << "Press '1' to generate a random string of length 50." << endl;
    cout << "Press '2' to generate a random string of length 100." << endl;

    typingTest.display(curr_word, str, total_letters, starting_time, userName);

    delete[] str;
    str = NULL;
    return 0;
}