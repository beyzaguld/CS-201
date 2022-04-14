#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

bool wordChecker(string word) {
	int i = 0;
	int len = word.length();
	string result;
	while (i < len) {
		if (word.at(i) >= 'a' && word.at(i) <= 'z') {
			i += 1;
		}
		else {
			return false;
		}
	}
	return true;
}

bool guessChecker(string letter_guess) {
	bool flag = false;
	if (letter_guess.length() > 1) {
		flag;
	}
	else if (letter_guess[0] >= 'a' && letter_guess[0] <= 'z') {
		flag = true;
	}
	return flag;
}

string WordToDash(string word, string & dash, string letter_guess) {
	int len = word.length();
	int index;
	if (letter_guess != "") {
		for (int i = 0; i < len-1; i++) {
			if (word.find(letter_guess, i) != -1) {
				index = word.find(letter_guess, i);
				dash.at(index) = letter_guess[0];
			}
	    }
	}
	return dash;
}

bool wordguessChecker(string word_guess) {
	bool flag = false;
	int i = 0;
	while (i < word_guess.length()) {
		if (word_guess[i] >= 'a' && word_guess[i] <= 'z') {
			flag = true;
		}
		else {
			flag = false;
			i = word_guess.length() + 1;
		}
		i += 1;
	}
	return flag;
}

int main() {
	string name1, name2, word, dash, guess;
	int live;
	cout << "Welcome to the HANGMAN GAME" << endl;
	cout << "---------------------------" << endl;
	cout << "Player one, please enter your name: ";
	cin >> name1;
	cout << "Player two, please enter your name: ";
	cin >> name2;
	cout << "OK " << name1 << " and " << name2 << ". Let's start the game!" << endl;
	cout << name1 << ", please input the word you want " << name2 << " to guess: ";
	cin >> word;
	ToLower(word);

	while (wordChecker(word) == false) {
		cout << "Invalid word! Try again." << endl;
		cout << name1 << ", please input the word you want " << name2 << " to guess: ";
		cin >> word;
		ToLower(word);
	}

	cout << name2 << ", you have 1 free guess, after that you will lose limbs!" << endl;
	live = 6;
	string falses = "";
	string option;
	string word_guess, letter_guess;
	letter_guess = "";
	int len = word.length();
	for (int i = 1; i <= len; i++) {
		dash = dash + "-";
	}
	while (live > 0 ) {
		cout << "The word is: " << WordToDash(word, dash, letter_guess) << endl;
		cout << name2 << ", do you want to guess the word(1) or guess a letter(2)? ";
		cin >> option;
		if (option == "1") {
			cout << "Your guess: ";
			cin >> word_guess;
			ToLower(word_guess);
			if (wordguessChecker(word_guess)) {
				if (word == word_guess) {
					cout << "The word is: " << word << endl;
					cout << "Congratulations " << name2 << ", you won!" << endl;
					cout << name2 << " won the game!";
					live = 0;
				}
				else if (word != word_guess) {
					if (live == 6) {
						cout << "You have no free guess left." << endl;
						live -= 1;
					}
					else if (live == 5) {
						cout << "You have lost a leg!" << endl;
						live -= 1;
					}
					else if (live == 4) {
						cout << "You have lost a leg!" << endl;
						live -= 1;
					}
					else if (live == 3) {
						cout << "You have lost an arm!" << endl;
						live -= 1;
					}
					else if (live == 2) {
						cout << "You have lost an arm!" << endl;
						live -= 1;
					}
					else if (live == 1) {
						cout << "You have lost a head! GAME OVER!" << endl;
						cout << name2 << " lost the game :(";
						live = 0;
					}
				}
			}
			else if (wordguessChecker(word_guess) == false) {
				cout << "Invalid entry! Try again." << endl;
			}		
		}
		else if (option == "2") {
			cout << "Your guess: ";
			cin >> letter_guess;
			ToLower(letter_guess);
			if (guessChecker(letter_guess)) {
				if (dash.find(letter_guess) == string::npos) {
					if (word.find(letter_guess) == string::npos) {
					  if (falses.find(letter_guess) == string::npos) {
							falses += letter_guess;
							if (live == 6) {
								cout << "You have no free guess left." << endl;
								live -= 1;
							}
							else if (live == 5) {
								cout << "You have lost a leg!" << endl;
								live -= 1;
							}
							else if (live == 4) {
								cout << "You have lost a leg!" << endl;
								live -= 1;
							}
							else if (live == 3) {
								cout << "You have lost an arm!" << endl;
								live -= 1;
							}
							else if (live == 2) {
								cout << "You have lost an arm!" << endl;
								live -= 1;
							}
							else if (live == 1) {
								cout << "You have lost a head! GAME OVER!" << endl;
								cout << name2 << " lost the game :(";
								live = 0;
							}
						}
						else {
							cout << "Guess entered before! Try again." << endl;
						}
					    letter_guess = ""; 
					} 
					else {
						if (WordToDash(word, dash, letter_guess)  == word) {
							cout << "The word is: " << word << endl;
							cout << "Congratulations " << name2 << ", you won!" << endl;
							cout << name2 << " won the game!";
							live = 0;
						}
					}
				}
				else {
					cout << "Guess entered before! Try again." << endl;
				} 
            }
		    else {
				cout << "Invalid entry! Try again." << endl;
				letter_guess = "";
		    }
		}
		else {
			cout << "Invalid option!" << endl;
		}
	}
	return 0;
}