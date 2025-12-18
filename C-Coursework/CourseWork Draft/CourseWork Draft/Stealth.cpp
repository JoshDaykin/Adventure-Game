#include"Stealth.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"debug.h"



/// Calculates success of speech attempt
/// param User = Gives access to stats and methods for the calculations
/// param Enemy = Gives access to stats and methods for the calcualations
bool SneakAttempt(Player* User, Enemies* Enemy) {
	srand(static_cast<unsigned int>(time(0))); // Seed random number
	int enemyAwareness = Enemy->getAwareness(); // Store enemies awareness

	int roll = rand() % 20 + 1; // Generate random number between 1 and 20
	int sneak = User->getSneak(); // Store sneak stat in sneak
	double successChance = roll + (sneak * 0.75); // Work out success chance using sneak stat

	DEBUG("Player sneak stat: " << User->getSneak());
	DEBUG("Enemy awareness: " << Enemy->getAwareness());
	DEBUG("Random sneak roll: " << roll);

	std::cout << "\nYou roll a dice to determine success...." << std::endl;
	std::cout << "You rolled: " << roll;

	if (successChance >= enemyAwareness) {
		std::cout << " and slipped by the enemy unnoticed.." << std::endl;
		return true; // Passed sneak attempt
	}
	else {
		std::cout << ". You've been spotted get ready for a fight..." << std::endl;
		return false; // Failed sneak attempt

	}
}