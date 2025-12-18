#pragma once
using namespace std;
#include<string>

/// Begins the game from the beginning and takes a new name and class from the user
/// Saves the name and class to the player class
/// param loadName = user inputted name
/// param loadClass = user inputted class
void newGame(string loadName, int loadClass);

/// Saves the game 
void saveGame(string playerName, string playerClass, int encounter, int alert);

/// <Data type to save player info>
/// <Name, Class, Encounter, alertStatus>
/// <returns></returns>
tuple<string, string, int, int>  loadGame();

///

/// Class Information ///
void showThiefInfo();
void showWarriorInfo();
void showBardInfo();
///

/// Encounter Management
void introduction();
void firstEncounter();
int playerDecision();
void encounterBreak();
void Encounter21();
void Encounter22();
void Encounter221();
void Encounter41();
void Encounter42();
///

///
