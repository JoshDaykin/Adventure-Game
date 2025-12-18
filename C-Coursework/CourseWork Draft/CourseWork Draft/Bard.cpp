#include"Bard.h"
#include<iostream>

//Constructor giving bard object specific stats
Bard::Bard() {
	health = 50;
	armour = 3;
	attack = 2;
	sneak = 5;
	speech = 10;
}

/// Calculates damage based on the enemies armour
/// enemyArmour bring the current enemies armour stat for the damage calculation
/// returns damage which is attack is doubled and then enemy armour is subtracted from it
float Bard::lightAttack(int enemyArmour) {
	int damage = (attack*2) - enemyArmour;
	std::cout << "You swing you dagger at them doing: " << damage << " points of damage." << std::endl;
	return damage;
}

/// Calculates damage based on the enemies armour
/// enemyArmour bring the current enemies armour stat for the damage calculation
/// returns damage which is attack is doubled and then enemy armour is ignored because they are distracted
/// Bards version of special attack
float Bard::specialAttack(int enemyArmour) {
	int damage;
	damage = (attack * 2) - (enemyArmour / enemyArmour);
	std::cout << "You point behind the bard attempting to distract him.\nThey actually look, leaving them open." << std::endl;
	std::cout << "Using this time time you strke dealing: " << damage << " Points of damage." << std::endl;
	return damage;
}

/// Getters
/// returns the specified stats for calculations
int Bard::getArmour()
{
	return armour;
}

int Bard::getHealth()
{
	return health;
}

int Bard::getSneak() {
	return sneak;
}

int Bard::getAttack() {
	return attack;
}


//Stat increases
void Bard::increaseAttack()
{
	attack += 2;
}

void Bard::increaseArmour()
{
	armour += 3;
}
