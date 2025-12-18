#pragma once
#include"Player.h"

/// Represents a class type for the player to use
/// Has higher attack skill but speech and sneak are low
/// Armour and atack are higher than other classes
class Warrior : public Player {
public:
	/// Constructor to give specific stats
	Warrior();

	/// Attacks
	/// Attacks
	/// Calculate attack damage based on enemy armour
	/// enemyArmour is the enemies armour stat
	/// special attack prints out class specific attack e.g. you throw your axe
	float lightAttack(int enemyArmour) override;
	float specialAttack(int enemyArmour) override;

	//Getters
	int getArmour() override;
	int getHealth() override;
	int getSneak() override;
	int getAttack() override;
	
	// Increase stats
	/// Functions that increases the players stats depending on what they pick up
	void increaseAttack() override;
	void increaseArmour() override;


};