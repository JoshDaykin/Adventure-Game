#include<iostream>
#include"Enemies.h"
#include<cstdlib>
#include<ctime>

using namespace std;

/// Getters for each stat
/// returns stat value for calculations
int Enemies::getHealth() {
	return health;
}

int Enemies::getArmour() {
	return armour;
}

int Enemies::getAttack() {
	return attack;
}

int Enemies::getAwareness()
{
	return awareness;
}

int Enemies :: getIntelligence() {
	return intelligence;
}

/// Damages the enemy
/// param dam = Players damage they dealt
void Enemies::enemyTakeDam(int dam) {
	health -= dam;
}

void Enemies::healEnemyHealth() {
	health = 50;
}

//Calculate random attack and return damage based on the players armour
float Enemies::randomAttack(int pArmour) {
	int damage; // Hold damage value
	//Generates the random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	//Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	//Check what attack is being used and calculate the damage
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) - pArmour;
		std::cout << "Gaurd dealt: " << damage << " points of damage" << std::endl;
		return damage; //Return the damage calculate
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Guard dealt: " << damage << " points of damage." << std::endl;
		return damage; //Return the calculated damage
	}
	else {
		return 0; //If the attack isn't light or heavy return 0 damage
	}

}

