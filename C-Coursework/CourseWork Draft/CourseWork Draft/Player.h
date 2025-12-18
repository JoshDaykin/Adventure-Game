#pragma once
#include<string>

//Parent class for the users choice of classes
class Player {
protected:

	/// Variables to store the name and chosen class of the user
	std::string playerName;
	std::string playerClass;
	/// Attributes that will be set by the class the user picks and the amount of potions the user has
	int health = 50, armour = 0, attack = 0, sneak = 0, speech = 0, potions = 0;

public:
	//Constructor & Destructor
	virtual ~Player() {};

	/// Attacking Moves
	/// Light attack returns damage based off of teh enemies armour
	/// param enemyArmour = enemies armour
	virtual float lightAttack(int enemyArmour) = 0;

	/// Players special attack that is different per subclass
	/// param enemyArmour = enemies armour
	/// returns damage based on enemy armour
	virtual float specialAttack(int enemyArmour);
	
	/// Setter
	/// sets the name based on the users input
	/// param name is the value of whatever the user decides
	void setName(std::string name);
	void setplayerClass(std::string choice);

	/// Getters
	/// Returns stat values and the players chosen name and class
	std::string getName();
	std::string getPlayerClass();
	virtual int getArmour();
	virtual int getHealth();
	virtual int getSneak();
	virtual int getSpeech();
	virtual int getAttack();

	/// Stat Increases
	/// Functions that increases the players stats depending on what they pick up
	virtual void increaseAttack();
	virtual void increaseArmour();

	/// Health Functions
	/// Player takes damage to health depending on the parameter
	/// param dam = The return value of the randomAttack() func by the enemy
	void playerTakeDam(int dam);
	void healPlayerHealth();

	/// Potions inventory management
	/// Adds a potion to the players inventory
	/// param amount = How many potions they pick up
	void addPotion(int amount = 1);

	/// Heals the players health
	void usePotion();

	/// Shows how many potions the user has left
	/// returns the amount of potions stored in the potions variable
	int getPotionCount() const;
};

