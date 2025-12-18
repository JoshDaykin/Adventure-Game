#pragma once
#include<map>
#include<iostream>

/// Parent class of all enemies
/// Creates virtual functions so all enemies can inherit and use them
/// creates attributes and allows the subclasses to alter them

class Enemies {
protected:
	/// Default stats
	/// Never used there is always an enemy to alter the stats
	int health = 50, armour = 0, attack = 0, awareness = 0, intelligence = 0;
	/// Hold all of the attacks for the enemy to use
	/// Light attack is the weaker, heavy attack is the higher damage return
	std::map<int, std::string> attacks = { {1,"Light Attack"}, {2, "Heavy Attack"} };

public:
	///Healing
	/// Enemy takes damage 
	/// dam parameter is the damage calculated from the attack function in the Player class
	void enemyTakeDam(int dam);
	void healEnemyHealth();
	

	/// Getters
	/// Returns values for each stat for calculations
	virtual int getHealth();
	virtual int getArmour();
	virtual int getAttack();
	virtual int getAwareness();
	virtual int getIntelligence();

	/// Combat Functions
	/// Uses a random move from the selection in the map
	/// pArmour = players armour
	virtual float randomAttack(int pArmour);
};