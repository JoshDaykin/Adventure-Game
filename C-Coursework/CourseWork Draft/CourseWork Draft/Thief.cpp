#include"Thief.h"
#include<iostream>


/// Constructor to give specific stats
Thief::Thief() {
	playerClass = "Thief";
	attack = 6;
	armour = 5;
	sneak = 10;
	speech = 4;
}

/// Calculates damage based on the enemies armour
/// enemyArmour bring the current enemies armour stat for the damage calculation
/// returns damage which is attack is doubled and then enemy armour is subtracted from it
float Thief::lightAttack(int enemyArmour) {
	int damage = (attack * 2) / enemyArmour;
	std::cout << "You slash out with both of your daggers dealing: " << damage << " points of damage." <<std::endl;
	return damage;
}

/// Getters for each stat
/// Returns stat values for calculations

float Thief::getThiefAttack(){
	return attack;
}

int Thief::getArmour()
{
	return armour;
}

int Thief::getHealth()
{
	return health;
}

int Thief::getSneak() {
	return sneak;
}

int Thief::getAttack() {
	return attack;
}

//Stat Increases
void Thief::increaseAttack()
{
	attack += 2;
}

void Thief::increaseArmour()
{
	armour += 3;
}


/// Calculates damage based on the enemies armour
/// EnemyArmour bring the current enemies armour stat for the damage calculation
/// Returns damage which is attack is doubled and then enemy armour is ignored because they are distracted
/// Thiefs version of special attack
float Thief::specialAttack(int enemyArmour) {
	int damage = attack * 2;
	std::cout << "You stab the enemy in the back inbetween their armour plates." << std::endl;
	std::cout << "Dealing: " << damage << " Points of damage." << std::endl;
	return damage;
}

