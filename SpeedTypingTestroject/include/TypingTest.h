#ifndef TYPINGTEST_H_
#define TYPINGTEST_H_

#include <string>
using namespace std;

class TypingTest
{
public:
    int timeSpan(int& starting_time);
    void calculation(char*& str, char current_word, int& total_letters, int& total_words);
    void display(char& curr_word, char*& str, int& total_letters, int& starting_time, const string& userName);
    string GenerateRandomString(int len);
};
#endif TYPINGTEST_H_