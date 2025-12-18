#pragma once
#include"Player.h"
#include"Enemies.h"

/// Calculates the chances of passing the speech check
/// param User = Gives access the players stats for calculations
/// param Enemy = Gives access to the current enemies stats for calculations
/// Returns true if they pass or false if they fail
bool speechAttempt(Player* User, Enemies* Enemy);