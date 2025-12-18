#pragma once
#include"Enemies.h"

/// <Brute>
///  High strength, low intelligence
class Brute : public Enemies {
public:
	///Constructor to give different stats
	Brute();

	/// Getter for each stat
	/// Returns stat values for calculations
	int getHealth() override;
	int getArmour() override;
	int getAttack() override;
	int getAwareness() override;
	int getIntelligence() override;

	/// Generates random attack
	/// Attacks stored in map in parent class
	/// pArmour is the players armour
	/// Returns damage based on player armour
	float randomAttack(int pArmour) override;
};



/// <Guard>
/// Low stats, tutorial enemy
class guard : public Enemies {
public:
	/// Constructor to give guard specific stats
	guard();
	~guard();

	/// Getters for each stat
	/// Returns stat values for calculations
	int getArmour() override;
	int getHealth() override;
	int getAttack() override;
	int getAwareness() override;
	int getIntelligence() override;

	/// Uses a random attack from the map stored in the player parent class
	/// Uses Blacksmiths attack stat
	/// pArmour = players armour
	/// Returns the damage calculated depending on the attack used
	float randomAttack(int pArmour) override;

};

/// Alert Bandit Leader
/// Higher attack / awareness
class awarebanditLeader : public Enemies {
public:
	//constructor
	awarebanditLeader();
	//Returns bandit armour value for use in damage function
	int getArmour() override;
	int getHealth() override;
	int getAttack() override;

	///Calculates and returns what attack to use and damage amoutn
	///Takes players armour as a parameter to scale the damage
	/// pArmour = players armour
	float randomAttack(int pArmour) override;

	//returns awareness level for use in the stealth mechanic
	int getAwareness() override;
	//returns intelligence level for use in speech mechanic
	int getIntelligence() override;
};

///Unaware Bandit Leader
/// <This is a more intelligent but less aware bandit leader enemy>
class unawarebanditLeader : public Enemies {
public:
	/// Constructor to give specific stats
	unawarebanditLeader();

	/// Getters
	/// Returns value of each stat
	int getArmour() override;
	int getHealth() override;
	int getAttack() override;
	int getAwareness() override;
	int getIntelligence() override;

	///Calculates and returns what attack to use and damage amoutn
	///Takes players armour as a parameter to scalre the damage
	/// pArmour = players armour
	float randomAttack(int pArmour) override;

};

///Blacksmith///
/// Type of enemy called blacksmith
/// An enemy that has higher intelligence but lower awareness

class Blacksmith : public Enemies {
public:
	/// Constructor to give blacksmith specific stats
	Blacksmith();

	/// Getters for each stat
	/// Returns stat values for calculations
	int getHealth() override;
	int getArmour() override;
	int getAttack() override;
	int getAwareness() override;
	int getIntelligence() override;

	/// pArmour = players armour
	/// Returns the damage calculated depending on the attack used
	float randomAttack(int pArmour) override;
};

///Royal Guard///
/// Type of enemy called blacksmith
/// An enemy that has higher intelligence and awareness
/// Higher armour and attack stats

class RoyalGuard : public Enemies {
public:
	/// Constructor to give specific stats
	RoyalGuard();

	/// Getters for each stat
	/// Returns stat values for calculations
	int getHealth() override;
	int getArmour() override;
	int getAttack() override;
	int getAwareness() override;
	int getIntelligence() override;

	/// Uses a random attack from the map stored in the player parent class
	/// Uses Blacksmiths attack stat
	/// pArmour = players armour
	/// Returns the damage calculated depending on the attack used
	float randomAttack(int pArmour) override;
};