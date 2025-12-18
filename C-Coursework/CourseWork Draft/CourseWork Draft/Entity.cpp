#include"Entity.h"


///Brute///
Brute::Brute()
{
	std::cout << "\nThe large man stares blankly..." << std::endl;
	attack = 8;
	armour = 3;
	awareness = 12;
	intelligence = 10;
}

/// Returns values for each stat
int Brute::getHealth()
{
	return health;
}

int Brute::getArmour()
{
	return armour;
}

int Brute::getAttack()
{
	return attack;
}

int Brute::getAwareness()
{
	return awareness;
}

int Brute::getIntelligence()
{
	return intelligence;
}

//Calculate random attack and return damage based on the players armour
float Brute::randomAttack(int pArmour) {
	int damage; // Hold damage value
	//Generates the random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	//Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	//Check what attack is being used and calculate the damage
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) - pArmour;
		std::cout << "Gaurd dealt: " << damage << " points of damage" << std::endl;
		return damage; //Return the damage calculate
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Guard dealt: " << damage << " points of damage." << std::endl;
		return damage; //Return the calculated damage
	}
	else {
		return 0; //If the attack isn't light or heavy return 0 damage
	}

}

///Guard///

//Stats
guard::guard() {
	armour = 2;
	attack = 3;
	awareness = 12;
	intelligence = 12;
}

guard::~guard() {
	std::cout << "You have defeated the guard." << std::endl;
}

/// Getters for each stat
/// Calculations
int guard::getArmour() {
	return armour;
}

int guard::getHealth()
{
	return health;
}

int guard::getAttack() {
	return attack;
}

int guard::getAwareness()
{
	return awareness;
}

int guard::getIntelligence()
{
	return intelligence;
}

//Calculate random attack and return damage based on the players armour
float guard::randomAttack(int pArmour) {
	int damage; // Hold damage value
	//Generates the random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	//Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	//Check what attack is being used and calculate the damage
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Gaurd dealt: " << damage << " points of damage" << std::endl;
		return damage; //Return the damage calculate
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Guard dealt: " << damage << " points of damage." << std::endl;
		return damage; //Return the calculated damage
	}
	else {
		return 0; //If the attack isn't light or heavy return 0 damage
	}

}


//constructor to give the enemy object stats
awarebanditLeader::awarebanditLeader() {
	armour = 7;
	attack = 8;
	awareness = 15;
	intelligence = 15;
}

//Armour getter
int awarebanditLeader::getArmour() {
	return armour;
}

//Health getter
int awarebanditLeader::getHealth()
{
	return health;
}
//Attack getter
int awarebanditLeader::getAttack() {
	return attack;
}

//Getter for awareness stat
int awarebanditLeader::getAwareness()
{
	return awareness;
}

//Getter for intelligence stat
int awarebanditLeader::getIntelligence()
{
	return intelligence;
}

//Calculate random attack and return damage based on the players armour
float awarebanditLeader::randomAttack(int pArmour) {
	int damage; // Hold damage value
	//Generates the random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	//Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	//Check what attack is being used and calculate the damage
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) - pArmour;
		std::cout << "Gaurd dealt: " << damage << " points of damage" << std::endl;
		return damage; //Return the damage calculate
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Guard dealt: " << damage << " points of damage." << std::endl;
		return damage; //Return the calculated damage
	}
	else {
		return 0; //If the attack isn't light or heavy return 0 damage
	}

}

/// Constructor for specific stats
unawarebanditLeader::unawarebanditLeader() {
	armour = 3;
	attack = 7;
	awareness = 10;
	intelligence = 15;
}


/// Getters for each stat
/// Returns stat values for calculations
int unawarebanditLeader::getArmour() {
	return armour;
}

int unawarebanditLeader::getHealth()
{
	return health;
}

int unawarebanditLeader::getAttack() {
	return attack;
}

int unawarebanditLeader::getAwareness()
{
	return awareness;
}

int unawarebanditLeader::getIntelligence()
{
	return intelligence;
}


//Calculate random attack and return damage based on the players armour
float unawarebanditLeader::randomAttack(int pArmour) {
	int damage; // Hold damage value
	//Generates the random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	//Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	//Check what attack is being used and calculate the damage
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) - pArmour;
		std::cout << "Gaurd dealt: " << damage << " points of damage" << std::endl;
		return damage; //Return the damage calculate
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Guard dealt: " << damage << " points of damage." << std::endl;
		return damage; //Return the calculated damage
	}
	else {
		return 0; //If the attack isn't light or heavy return 0 damage
	}

}

///Blacksmith///
/// Constructor giving specific stats
Blacksmith::Blacksmith()
{
	std::cout << "\nThe old man wakes up quickly." << std::endl;
	attack = 6;
	armour = 5;
	awareness = 12;
	intelligence = 14;
}


/// Getters
/// Returns value for each stat
int Blacksmith::getHealth()
{
	return health;
}

int Blacksmith::getArmour()
{
	return armour;
}

int Blacksmith::getAttack()
{
	return attack;
}

int Blacksmith::getAwareness()
{
	return awareness;
}

int Blacksmith::getIntelligence()
{
	return intelligence;
}

//Calculate random attack and return damage based on the players armour
float Blacksmith::randomAttack(int pArmour) {
	int damage; // Hold damage value
	// Generate random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	// Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	// Check what attack is being used
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) / pArmour;
		return damage; // Return the calculated damage
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 3) - (pArmour / 2);
		return damage;
	}
	else {
		return 0; // If the attack isn't light or heavy return 0 damage
	}

}

///Royal Guard///
/// Constructor to give specific stats
RoyalGuard::RoyalGuard()
{
	std::cout << "\nThe guard looks at you piercingly..." << std::endl;
	attack = 6;
	armour = 4;
	awareness = 15;
	intelligence = 13;
}

/// Getters to return stats for calculations
/// Returns each stat value
int RoyalGuard::getHealth()
{
	return health;
}

int RoyalGuard::getArmour()
{
	return armour;
}

int RoyalGuard::getAttack()
{
	return attack;
}

int RoyalGuard::getAwareness()
{
	return awareness;
}

int RoyalGuard::getIntelligence()
{
	return intelligence;
}

//Calculate random attack and return damage based on the players armour
float RoyalGuard::randomAttack(int pArmour) {
	int damage; // Hold damage value
	//Generates the random number to select an attack from the map
	int randomNum = (rand() % attacks.size()) + 1;

	//Print the attack being used
	std::cout << "Enemy used: " << attacks[randomNum] << std::endl;

	//Check what attack is being used and calculate the damage
	if (attacks[randomNum] == "Light Attack") {
		//For light attack damage double the attack stata and subtract the players armour
		damage = (attack * 2) - pArmour;
		std::cout << "Gaurd dealt: " << damage << " points of damage" << std::endl;
		return damage; //Return the damage calculate
	}
	else if (attacks[randomNum] == "Heavy Attack") {
		//For heavy attack the damage is double and the players armour is halved
		damage = (attack * 2) - (pArmour / 2);
		std::cout << "Guard dealt: " << damage << " points of damage." << std::endl;
		return damage; //Return the calculated damage
	}
	else {
		return 0; //If the attack isn't light or heavy return 0 damage
	}

}



