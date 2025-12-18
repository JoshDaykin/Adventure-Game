#include"Player.h"
#include"Enemies.h"
#include<iostream>

/// Sets the name based on the param
/// param = Users inputted name
void Player::setName(std::string name) {
	playerName = name;
}
/// Calculates players damange based on enemy armour
/// param enemyArmour = enemies current armour
/// returns the damage from the calculations
float Player::specialAttack(int enemyArmour){
	int damage = (attack * 2) - (enemyArmour / 2);
	return damage;
}

void Player::setplayerClass(std::string choice) {
	playerClass = choice;
}

std::string Player::getName() {
	return playerName;
}

std::string Player::getPlayerClass() {
	return playerClass;
}

int Player::getArmour()
{
	return armour;
}

/// Player takes damaged based on dam
/// dam = damage calculated by enemies attack
/// dam is subtracted from health
void Player::playerTakeDam(int dam) {
	health = health -= dam;
}

void Player::healPlayerHealth() {
	health = 50;
}

/// Adds potions to the players inventory
/// Dependant on amount param
/// param amount = how many potions were picked up
void Player::addPotion(int amount)
{
	potions += amount;
	std::cout << "You now have " << potions << " potions." << std::endl;
}

/// Players heals their health with a potion
void Player::usePotion()
{
	if (potions > 0) {
		if (health > 50) {
			health = 50;
			// If health is already max it stays at max
			std::cout << "You are already at max health." << std::endl;
		}
		else if (health < 50) {
			health += 15;
			std::cout << "You used a potion. Your health is now: " << health << std::endl;
			potions--;
		}
		else {
			std::cout << "You have no potions left!" << std::endl;
		}
	}
	else if (potions < 0) {
		std::cout << "You have no potions left" << std::endl;
	}
}

// Returns value of potions variable
int Player::getPotionCount() const
{
	return potions;
}


/// Getters for stats for calculations
/// Returns each stat value
int Player::getHealth() {
	return health;
}

int Player::getSneak() {
	return sneak;
}

int Player::getSpeech()
{
	return speech;
}

int Player::getAttack() {
	return attack;
}



/// Stat Increases
/// Increases stat depending on item found
void Player::increaseAttack()
{
	attack += 2;
}

void Player::increaseArmour()
{
	armour += 3;
}


