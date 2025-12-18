#include"Combat.h"
#include"debug.h"


/// Manages each fight sequence
/// param User = gives access to stats and methods needed for calculating damage and health
/// param Enemy = gives access to stats and methods for calculating damage and health
void Fight(Player* User, Enemies* Enemy) {
    float pAttack; // Stores the players attack

    /// As long as neither player or enemy is at 0 health keep running
    while (Enemy->getHealth() > 0 and User->getHealth() > 0) {
        int enemyArmour = Enemy->getArmour(); // Store enemy armour value
            //Options for attack
            std::cout << "\nWhat move will you use?";
            std::cout << "\n1)Light Attack\n2)Special Attack\n3)Use Potion\t" << User->getPotionCount() << " Potions left" << std::endl;
            std::cin >> pAttack; std::cout << "\n";
            if (pAttack == 1) {
                float damageTaken = User->lightAttack(enemyArmour); // Calculate damage value

                //Damage the enemy using the calculated amount
                Enemy->enemyTakeDam(damageTaken);
            }
            else if (pAttack == 2) {
                float damageTaken = User->specialAttack(enemyArmour); // Apply specialAttack formula to calculate damage


                //Damage the enemy with calculated damage
                Enemy->enemyTakeDam(damageTaken);
                DEBUG("Damage dealt by player: " << damageTaken);
                DEBUG("Enemy health after attack: " << Enemy->getHealth());
                //Check enemy is alive or dead
                if (Enemy->getHealth() <= 0) {
                    break; // Exit loop if enemy is dead
                }
               
            }
            else if (pAttack == 3) {
                User->usePotion(); // Uses a health potion and restores players health
                continue;
            }

            // Enemies Attack
            std::cout << "\nGuards turn:" << std::endl;

            // Calculate damage based on users armour
            float enemyDamage = Enemy->randomAttack(User->getArmour()); 

            // Damage the players health using the calculated enemyDamage
            User->playerTakeDam(enemyDamage);

            //Show health left after every attack
            std::cout << "\nGuard Health Remaining: " << Enemy->getHealth() << std::endl;
            std::cout << "Your remaining health: " << User->getHealth() << std::endl;

            DEBUG("Enemy deals: " << enemyDamage << " damage to player");
            DEBUG("Player HP after enemy attack: " << User->getHealth());
            


       }
        if (User->getHealth() <= 0) {
            std::cout << "You were killed..." << std::endl;
            exit(0);
        }
        else if (Enemy->getHealth() <= 0) {
            std::cout << "You defeated the guard!\n" << std::endl;
        
    }
}