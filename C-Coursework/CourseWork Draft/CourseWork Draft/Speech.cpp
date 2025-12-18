#include"Speech.h"
#include<iostream>
#include"debug.h"


/// Calculates success of speech attempt
/// param User = Gives access to stats and methods for the calculations
/// param Enemy = Gives access to stats and methods for the calcualations
bool speechAttempt(Player* User, Enemies* Enemy)
{
	int enemyIntell = Enemy->getIntelligence(); // Store enemies intelligence level

	srand(static_cast<unsigned int>(time(0))); // Seed random number

	int roll = rand() % 20 + 1; // Generate a random number between 1 and 20
	float speech = User->getSpeech(); // Store speech stat value
	float successChance = roll + (speech * 0.75); // Calculate chance based on speech stat

	DEBUG("Player speech stat: " << User->getSpeech());
	DEBUG("Enemy intelligence: " << Enemy->getIntelligence());
	DEBUG("Random speech roll: " << roll);


	std::cout << "\nYou roll a dice to determine success...." << std::endl;
	std::cout << "You rolled: " << roll;

	if (successChance >= Enemy->getAwareness()) {
		return true; // Passed speech test
	}
	else if (successChance <= Enemy->getAwareness()) {
		return false; // Failed speech test
	}
	else {
		return false;
	}
}

