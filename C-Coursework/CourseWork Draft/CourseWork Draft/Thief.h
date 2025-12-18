#pragma once
#include"Player.h"

/// Represents a class type for the player to use
/// Has higher sneak skill 
/// Armour and atack are lower 
class Thief : public Player {
public:
	//Constructor to give specific stats
	Thief();

	///Attacks
	///Calculate attack damage based on enemy armour
	///enemyArmour is the enemies armour stat
	/// special attack prints out class specific attack e.g. you stab them in the back
	float lightAttack(int enemyArmour) override;
	float getThiefAttack();
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