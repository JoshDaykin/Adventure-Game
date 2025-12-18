#include"Warrior.h"
#include<iostream>

// Constructor for specific stats
Warrior::Warrior() {
	playerClass = "Warrior";
	attack = 10;
	armour = 7;
	sneak = 2;
	speech = 1;
}

/// Calculates damage based on the enemies armour
/// enemyArmour bring the current enemies armour stat for the damage calculation
/// returns damage which is attack is doubled and then enemy armour is subtracted from it
float Warrior::lightAttack(int enemyArmour) {
	float damage = attack - (enemyArmour / 2);
	std::cout << "You swing your heavy sword dealing: " << damage << " points of damage." << std::endl;
	return damage;
}

/// Calculates damage based on the enemies armour
/// enemyArmour bring the current enemies armour stat for the damage calculation
/// returns damage which is attack is doubled and then enemy armour is ignored because they are distracted
/// Warriors version of special attack
float Warrior::specialAttack(int enemyArmour) {
	float damage = (attack * 2) - (enemyArmour / 2);
	std::cout << "Warrior heavy attack did: " << damage << " points of damage." << std::endl;
	return damage;
}

/// Getters for each stat
/// Returns stat value for calculation
int Warrior::getArmour()
{
	return armour;
}

int Warrior::getHealth() {
	return health;
}

int Warrior::getSneak() {
	return sneak;
}

int Warrior::getAttack() {
	return attack;
}


// Stat increases
void Warrior::increaseAttack()
{
	attack += 2;
}

void Warrior::increaseArmour()
{
	armour += 3;
}
