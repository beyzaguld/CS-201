#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	cout << "Hello and welcome to the Hogwarts house sorting hat program!" << endl;
	cout << "When I call your name, you'll come forth, I shall place the sorting hat on your head, and you will be sorted into your houses." << endl;
	string keyname, answername;
	ifstream keyFile, ansFile;
	cout << "Enter the name of the key file: ";
	cin >> keyname;
	keyFile.open(keyname.c_str());
	while (keyFile.fail()) {
		cout << "Error: Cannot open file " << keyname << endl;
		cout << "Enter the name of the key file: ";
		cin >> keyname;
		keyFile.clear();
		keyFile.open(keyname.c_str());
	}


	cout << "Enter the name of the answer file: ";
	cin >> answername;
	ansFile.open(answername.c_str());
	while (ansFile.fail()) {
		cout << "Error: Cannot open file " << answername << endl;
		cout << "Enter the name of the answer file: ";
		cin >> answername;
		ansFile.clear();
		ansFile.open(answername.c_str());
	}


	string line, keyline, word, keyword, name, surname, type;
	while (getline(ansFile, line)) {
		if (line != "" && line != "\r") {
			int score = 0;
			istringstream ss(line);
			ss >> name >> surname;
			int wordposition = 1;
			int counter = 1;
			while (ss >> word) {
				int i = 1;
				while (getline(keyFile, keyline)) {	
					if (keyline != "" && keyline != "\r") {
						if ( counter == i) {
							istringstream key(keyline);
							int keyword_pos = 1;
							while (key >> keyword) {
								if (keyword == word) {
									score += keyword_pos;
								}
								keyword_pos++;
							}
						}
						i++;
					}
				}
				keyFile.clear();
				keyFile.seekg(0);
				counter++;
			}
			if (score < 10) {
				type = "Hufflepuff";
			}
			else if (score >= 10 && score < 15) {
				type = "Ravenclaw";
			}
			else if (score >= 15 && score < 21) {
				type = "Gryffindor";
			}
			else if (score >= 21) {
				type = "Slytherin";
			}
			cout << "Oh! we have " << name << " " << surname << " under the sorting hat. " 
				<< name << ", you scored " << score << " points, you are a " << type << "!" << endl;
		}
	}
	keyFile.close();
	ansFile.close();
	return 0;
}