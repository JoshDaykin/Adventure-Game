#include<string>
#include<iostream>
#include<fstream>
#include<utility>
#include"debug.h"
#include<tuple>
#include "GameManager.h"
#include"Enemies.h"
#include"Player.h"

/// Start of game saving and loading functions
using namespace std;
/// File Saving
/// Starts the game from the first encounter
/// Creates a new file called save 1
/// param loadName = Users inputted name
/// param loadClass = Users chosen inputted class
void newGame(string loadName, int loadClass) {
		string pClass;
		ofstream gameSave("Save1.txt");
		if (loadClass == 1) {
			pClass = "Warrior";
		}
		else if (loadClass == 2) {
			pClass = "Thief";
		}
		else if (loadClass == 3) {
			pClass = "Bard";
		}
		else {
			cout << "You need to pick 1,2 or 3." << endl;
		}
		/// Writes it to the file and closes the file
		gameSave << loadName << endl << pClass << endl;
		DEBUG("Saving to file: Name = " << loadName << ", Class = " << pClass);
		gameSave.close();
	}

/// Saves current game progress
void saveGame(string playerName, string playerClass, int encounter, int alert) {
	ofstream gameSave("Save1.txt");
	if (gameSave.is_open()) {
		gameSave << playerName << endl << playerClass << endl << encounter << endl << alert << endl;
		DEBUG("Saving to file: playerName = " << playerName << endl << "Class: " << playerClass << endl << "Encounter number: " << encounter << endl << "Alert level: " << alert << endl)
			gameSave.close();
	}
	else {
		cerr << "Failed to save game." << endl;
	}
}

tuple<string, string, int, int> loadGame(){
	int encounter = 0;
	int alertStatus = 0;
	string loadName, loadClass;
	ifstream saveFile;
	try {
		saveFile.open("Save1.txt");
		if (!saveFile.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		/// Saves the first line in loadName
		getline(saveFile, loadName);
		/// Saves the second line in loadClass
		getline(saveFile, loadClass);
		// Saves the encounter number in savefile
		saveFile >> encounter;
		// Saves the alert status in savefile
		saveFile >> alertStatus;
		DEBUG("Loading from file: loadName = " << loadName << endl << "Class: " << loadClass << endl << "Encounter number: " << encounter << endl << "Alert level: " << alertStatus << endl)
			saveFile.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
	return { loadName, loadClass, encounter, alertStatus };
}

/// End of game saving and loading functions

/// Start of Class information functions /// 
void showThiefInfo() {
	ifstream thiefFile;
	string thiefInfo;
	try {
		thiefFile.open("Thief Dossier.txt");
		if (!thiefFile.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(thiefFile, thiefInfo)) {
			cout << thiefInfo << endl;
		}
		thiefFile.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

void showWarriorInfo() {
	ifstream warriorFile;
	string warriorInfo;
	try {
		warriorFile.open("Brawler Dossier.txt");
		if (!warriorFile.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(warriorFile, warriorInfo)) {
			cout << warriorInfo << endl;
		}
		warriorFile.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

void showBardInfo() {
	ifstream bardFile;
	string bardInfo;
	try {
		bardFile.open("Bard Dossier.txt");
		if (!bardFile.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(bardFile, bardInfo)) {
			cout << bardInfo << endl;
		}
		bardFile.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}
/// End of Class information functions ///

/// Start of Encounter management functions
void introduction() {
	ifstream introductionFile; // Variable name of file
	string read; // Store contents in this variable
	try {
		introductionFile.open("Introduction.txt"); // Attempt to open the file
		if (!introductionFile.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		// Reads each line of the file storing values in read variable
		while (getline(introductionFile, read)) {
			// Displays the value of read
			cout << read << endl;
		}
		introductionFile.close(); // Close the file
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl; // Catches the error instead of crashing and shows why it failed
	}
}

void firstEncounter() {
	ifstream encounterFile; // Variable name of file
	string read; // Store contents in this variable
	try {
		encounterFile.open("Tutorialencounter.txt"); // Attempt to open the file
		if (!encounterFile.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		// Reads each line of the file storing values in read variable
		while (getline(encounterFile, read)) {
			// Displays the value of read
			cout << read << endl;
		}
		encounterFile.close(); // Close the file
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl; // Catches the error instead of crashing and shows why it failed
	}
}

/// Spaces out each encounter reading to make it a better user experience
void encounterBreak() {
	cout << "\n*****************************************************************************\n" << endl;
}

/// Allows player to input a number
int playerDecision() {
	int playerDecision;
	cin >> playerDecision;
	/// Returns the number so it can be used in if statements
	while (cin.fail() || playerDecision != 1 && playerDecision != 2 && playerDecision != 3 && playerDecision != 4) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You must choose 1, 2 or 3." << endl;
		cin >> playerDecision;
	}
	return playerDecision;
}

/// Ends of encounter management functions

/// Start of encounter functions
void Encounter21() {
	ifstream encounter21File;
	string read;
	try {
		encounter21File.open("Encounter2.1.txt");
		if (!encounter21File.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(encounter21File, read)) {
			cout << read << endl;
		}
		encounter21File.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

void Encounter22()
{
	ifstream encounter22File;
	string read;
	try {
		encounter22File.open("Encounter2.2.txt");
		if (!encounter22File.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(encounter22File, read)) {
			cout << read << endl;
		}
		encounter22File.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

void Encounter221()
{
	ifstream encounter221File;
	string read;
	try {
		encounter221File.open("Encounter 2.21.txt");
		if (!encounter221File.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(encounter221File, read)) {
			cout << read << endl;
		}
		encounter221File.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

void Encounter41()
{
	ifstream encounter41File;
	string read;
	try {
		encounter41File.open("Encounter 4.1.txt");
		if (!encounter41File.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(encounter41File, read)) {
			cout << read << endl;
		}
		encounter41File.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

void Encounter42()
{
	ifstream encounter42File;
	string read;
	try {
		encounter42File.open("Encounter 4.2.txt");
		if (!encounter42File.is_open()) {
			throw ios_base::failure("Failed to open the file.");
		}
		while (getline(encounter42File, read)) {
			cout << read << endl;
		}
		encounter42File.close();
	}
	catch (const ios_base::failure& e) {
		cerr << "File handling error: " << e.what() << endl;
	}
}

/// End of encounter functions

/// Start of stat roll functions
/// Sneak / Speech attempt

