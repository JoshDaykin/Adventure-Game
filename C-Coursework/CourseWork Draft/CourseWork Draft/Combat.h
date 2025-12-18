#pragma once
#include"Player.h"
#include"Enemies.h"

/// Function for the combat sequence
/// Uses player and enemy functions to deal damage and take damage
/// Player* User = The users class so it uses the right class and version of methods
/// Enemies* Enemy = The enemies class so it uses the right class and version of methods
void Fight(Player* User, Enemies* Enemy);