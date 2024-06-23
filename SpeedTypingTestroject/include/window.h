#ifndef WINDOW_H_
#define WINDOW_H_
#include <iostream>

using namespace std;
class window_cl
{
protected:
	string name;
public:
	window_cl();

	void space();
	string startscreen();
	void homescreen(string name);
	int UserIntefaceStartScreen(char& current_word, string UserName);
	void userStatics(int total_words, int total_letters, int seconds,const string name, int wrongs);
};
#endif // !WINDOW_H_
