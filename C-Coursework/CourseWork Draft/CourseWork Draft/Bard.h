#pragma once
#include"Player.h"

/// Represents a class type for the player to use
/// Has higher speech skill but attack and sneak are low
/// Armour and atack are lower than other classes
class Bard : public Player {
public:
	//Constructor to give different stats
	Bard();

	/// Attacks
	/// Calculate attack damage based on enemy armour
	/// enemyArmour is the enemies armour stat
	/// special attack prints out class specific attack e.g. bard distracts opponent and then attacks
	float lightAttack(int enemyArmour) override;
	float specialAttack(int enemyArmour) override;

	//Getters
	int getArmour() override;
	int getHealth() override;
	int getSneak() override;
	int getAttack() override;

	/// Stat Increases
	/// Functions that increases the players stats depending on what they pick up
	void increaseAttack() override;
	void increaseArmour() override;
};