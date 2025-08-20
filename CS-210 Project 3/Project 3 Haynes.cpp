//Joey Haynes
//8-16-2025
//CS-210 Project 3 Submission

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

//Prompt menu screen and user input
int getMenu() {
	int option;
	cout << "Menu options: \n";
	cout << "1. Look up item frequencies\n";
	cout << "2. List item frequencies\n";
	cout << "3. Show item frequency histogram\n";
	cout << "4. Exit\n";
	cout << "Enter your option (1-4)";
	cin >> option;
	return option;
}

//Function for option 1
void lookItemFreq(const map<string, int>& itemFreq) {
	string item;
	cout << "Enter the item you are wanting to look up: ";
	cin >> item;

	auto iter = itemFreq.find(item);
	if (iter != itemFreq.end()) {
		cout << item << " frequency: " << iter->second << endl;
	}

	else {
		cout << "Item not found." << endl;
	}
}

//Function for option 2
void listItemFreq(const map<string, int>& itemFreq) {
	cout << "Item Frequencies: \n";
	for (const auto& pair : itemFreq) {
		if (!outputFile.is open()) {
			cout << "Error opening output file." << endl;
			return 1;
		}

		//Add backup files
		for (const auto& pair : itemFreq) {
			outputFile << pair.first << " " << pair.second << endl;
		}
		outputFile.close();

		int option;
		do {
			option = getMenu;
			switch (option) {
			case 1:
				lookItemFreq(itemFreq);
				break;

			case 2:
				listItemFreq(itemFreq);
				break;

			case 3:
				itemFreqHisto(itemFreq);
				break;

			case 4:
				cout << "Closing program." << endl;

			default:
				cout << "Invalid option. Please try again." << endl;
			}

			cout << endl;
		} while (option != 4);
			cout << pair.first << " " << pair.second << endl;
	}
}

void itemFreqHisto(const map<string, int>& itemFreq) {
	cout << "Item frequency histogram: \n";
	for (const auto& pair : itemFreq) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout >> endl;
	}
}

int option() {
	fstream inputFile("Input.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening input file. Please try again." << endl;
		return 1;
	}

	map<string, int> itemFreq;

	//List items from file
	string item;
	while (inputFile >> item) {
		itemFreq(item)++;
	}
	inputFile.close();

	//Make backup file and open it
	offstream outputFile("frequency.dat");
	while (option != 4) {
		return 0;
	}
}