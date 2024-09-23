/*
* hangman.cpp
*
*  Created on: 27 Jul 2022
*      Author: Acer
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#define arrSize(a) sizeof(a)/sizeof(a[0])
using namespace std;
int randInt(int a, int b){
	return (rand() % (b - a + 1)) + a;
}
int main(){
	string frames[] = {
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |        \n"
			" |        \n"
			" |        \n"
			" |        \n"
			"/|\\       \n",
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |       O\n"
			" |        \n"
			" |        \n"
			" |        \n"
			"/|\\       \n",
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |       O\n"
			" |       |\n"
			" |        \n"
			" |        \n"
			"/|\\       \n",
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |       O\n"
			" |       |\\\n"
			" |        \n"
			" |        \n"
			"/|\\       \n",
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |       O\n"
			" |      /|\\\n"
			" |        \n"
			" |        \n"
			"/|\\       \n",
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |       O\n"
			" |      /|\\\n"
			" |       |\n"
			" |        \n"
			"/|\\       \n",
			" _________\n"
			" |       |\n"
			" |       |\n"
			" |       O\n"
			" |      /|\\\n"
			" |       |\n"
			" |        \\\n"
			"/|\\       \n",
			" _________   \n"
			" |       |   \n"
			" |       |   \n"
			" |       O   \n"
			" |      /|\\ \n"
			" |       |   \n"
			" |      / \\ \n"
			"/|\\         \n",
	};
	srand(time(0));
	int size = arrSize(frames);
	int tries = size;
	string words[] = {"intelligence", "embedded", "arithmetic","object",
			"oriented", "functional", "directive"};
	string word = words[randInt(0, size)-1];
	int length = word.length();
	char guess;
	char unknown[length];
	for (int i = 0; i<length; i++) unknown[i] = '_';
	do {
		cout << frames[size-tries];
		for (char ch : unknown) cout << ch;
		cout << endl;
		cout << "Enter a letter:";
		cin >> guess;
		int correct = 0;
		for (int i = 0; i<length; i++){
			if (guess == word[i]){
				cout << "You've guessed correctly!" << endl;
				correct = 1;
				for (int j = 0; j<length; j++){
					if (guess == word[j]) unknown[j] = guess;
				}
				if (unknown == word){
					cout << "You've won! Good job! The word was "<< word << endl;
					tries = 0;
				}
				break;
			}
		}
		if (!correct) {
			tries--;
			if (tries == 0)cout << "You've lost all of your tries! The word was " << word << endl;
			if (tries > 0) cout << "Your guess was wrong! You've lost " << size - tries << (tries == (size-1) ? " try" : " tries") << endl;
		}
	} while (tries > 0);
	cout << endl;
	return 0;
}


