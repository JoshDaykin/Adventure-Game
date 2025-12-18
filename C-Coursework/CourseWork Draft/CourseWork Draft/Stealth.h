#pragma once
#include"Player.h"
#include"Enemies.h"

/// Calculates the chances of passing the sneak check
/// param User = Gives access the players stats for calculations
/// param Enemy = Gives access to the current enemies stats for calculations
/// Returns true if they pass or false if they fail
bool SneakAttempt(Player* User, Enemies* Enemy);