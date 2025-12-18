// CourseWork Draft.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include<utility>
#include <string>
#include"Player.h"
#include"Enemies.h"
#include"Warrior.h"
#include"Thief.h"
#include"Bard.h"
#include"Entity.h"
#include"Combat.h"
#include"Stealth.h"
#include"Speech.h"
#include"debug.h"
#include"GameManager.h"


using namespace std;

// Displays game title screen
void Title() {
    cout << "*******************************************" << endl;
    cout << "The search for the chalice of Anadon" << endl;
    cout << "*******************************************" << endl;
}

int main()
{
    // Player and Enemy class pointers
    Player* User = nullptr;
    Enemies* Enemy = nullptr;

    // Game variables
    int pClass = 0, finalChoice, alertStatus = 0, eTracker = 0, playerApproach = 0, location = 0, encounter = 0;
    bool sneakPassed, speechPassed;
    string name;

    //Show the title of the game
    Title();

    //Asks to start new or load previous save
    int newOrload;
    cout << "1)New Game\n2)Load Game" << endl;
    cin >> newOrload;
    /// Catches Invalid input and asks for correct input
    while (cin.fail() || newOrload != 1 && newOrload != 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You must choose 1 or 2." << endl;
        cin >> newOrload;
    }

    // ========== NEW GAME ========== //
    if (newOrload == 1) {
        cout << "Begin by picking a class." << endl;
        // Allos user to view information about each class until they decide
        while (pClass != 4) {
            cout << "Select a class to learn more about it:\n1)Warrior\n2)Thief\n3)Bard" << endl;
            cout << "Press 4 when you are ready to decide." << endl;
            cin >> pClass;
            DEBUG("User selected class to preview: " << pClass);
            while (cin.fail() || pClass != 1 && pClass != 2 && pClass != 3 && pClass != 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You must choose a class." << endl;
                cin >> pClass;
            }

            //Show Warrior details
            if (pClass == 1) {
                showWarriorInfo();
            }
            //Show Thief details
            else if (pClass == 2)
            {
                showThiefInfo();
            }
            //Show Bard details
            else if (pClass == 3) {
                showBardInfo();
            }
        }
        // Final class selection
        std::cout << "So which class will it be?:\n1)Warrior\n2)Thief\n3)Bard " << endl;
        cin >> finalChoice;
        DEBUG("User final choice: " << finalChoice);
        while (cin.fail() || finalChoice != 1 && finalChoice != 2 && finalChoice != 3 && finalChoice != 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You must choose a class." << endl;
            cin >> finalChoice;
        }

        //Creates a new player with correct stats based on users choice
        if (finalChoice == 1) {
            User = new Warrior();
            User->setplayerClass("Warrior");
        }
        else if (finalChoice == 2) {
            User = new Thief();
            User->setplayerClass("Thief");
        }
        else if (finalChoice == 3) {
            User = new Bard();
            User->setplayerClass("Bard");
        }

        // Asks for users Name
        cout << "What is your name?: " << endl;
        cin >> name;
        DEBUG("PLayer entered name: " << name);
        User->setName(name);

        //Saves the name and class chosen
        newGame(name, finalChoice);

        cout << "\n";

        // ======== Read introduction to game ======== //
        introduction();

    }

    // ========= LOAD GAME ========= //
    else if (newOrload == 2) {
        // Retrieve saved name and class
        string loadName, loadClass;
        int savedEncounter, alert;
        // Unpack saved values into variables
        tie(loadName, loadClass, savedEncounter, alert) = loadGame();
        encounter = savedEncounter;
        alertStatus = alert;

        // Creates new player with correct stats based on saved data
        if (loadClass == "Warrior") {
            User = new Warrior();
            finalChoice = 1;
        }
        else if (loadClass == "Thief") {
            User = new Thief();
            finalChoice = 2;
        }
        else if (loadClass == "Bard") {
            User = new Bard();
            finalChoice = 3;
        }
        // Sets the players name
        User->setName(loadName);
        // Remind player of their character details
        cout << "Class Reminder: " << loadClass << "\nName Reminder: " << loadName;
    }

    //Splits encounters on screen
    encounterBreak();


    if (encounter == 0) {
        // ========== Encounter 1 ========== //
        firstEncounter();

        // Get players approach decision (Fight/ sneak/ attack)
        eTracker = playerDecision();

        // Create new enemy for this encounter
        Enemy = new guard();

        // ========== Combat outcome ========== //
        if (eTracker == 1) {
            Fight(User, Enemy);
            delete Enemy;
            alertStatus = 2; // Alert raised due to combat
        }
        // ========== Sneak Outcome ========== //
        else if (eTracker == 2) {
            //Successful Sneak
            sneakPassed = SneakAttempt(User, Enemy);
            if (sneakPassed == true) {
                delete Enemy;
                alertStatus = 1;
            }
            //Failed Sneak
            else if (sneakPassed == false) {
                Fight(User, Enemy);
                delete Enemy;
                alertStatus = 2; // Alert raised due to failed sneak
            }
        }
        // ========== Speech Outcome ========== //
        else if (eTracker == 3) {
            speechPassed = speechAttempt(User, Enemy);
            if (speechPassed == true) {
                cout << ". \nYou convinced the guard you're a diplomat, they let you through the gate..." << std::endl;
                delete Enemy;
                alertStatus = 1;
            }
            else if (speechPassed == false) {
                Fight(User, Enemy);
                std::cout << "The guard checks the roster and doesn't see your name, without hesitation he attacks..." << std::endl;
                delete Enemy;
                alertStatus = 2; // Alert raised due to failed speech attempt
            }
        }
        // ========== Exit and save ========== //
        else if (eTracker == 4) {
            saveGame(User->getName(), User->getPlayerClass(), encounter, alertStatus);
            cout << "The game has been saved." << endl;
            delete User;
            delete Enemy;
            exit(0);
        }
    }
    else {
        cout << "Loading game..." << endl;
    }

    // ========== Encounter 2 ========== //
    encounter = 1; // Track encounter

    // Separate and show new encounter
    encounterBreak();

    // ========== Checks encounter ========== // 
    if (encounter == 1) {
        // ========== PATH 1: Player was not caught or they passed sneak / speech atempt ========== //
        if (alertStatus == 1) {
            Encounter22(); // Show the encounter for this scenario
            eTracker = playerDecision(); // Get the players approach 1 = speech, 2 = sneak, 3 = attack
            Enemy = new guard(); // Spawn new guard for this scenario


            // ========== Speech Approach ========== //
            if (eTracker == 1) {
                speechPassed = speechAttempt(User, Enemy);// Attempt speech check

                //Successful speech attempt guard explains the doors
                if (speechPassed == true) {
                    cout << "\nThe guard begins to question who you are..." << endl;
                    cout << "But after you explain you're the new recruit he tells you what each door leads to." << endl;
                    Encounter221(); // Show room options
                    alertStatus = 1; // Stays undetected
                    //Alchemy lab
                    location = 3;
                }
                //Failed speech attempt: guard attacks
                else if (speechPassed == false) {
                    cout << "\nHe can clearly see you aren't a Jeweller, from your appearance.." << endl;
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    alertStatus = 2; // You've been detected
                    // Armoury
                    location = 2;
                }
            }
            // ========== Sneak Approach ========== //
            else if (eTracker == 2) {
                cout << "The guard looks half-dozed you try to sneak past down the expensive looking door in the middle?" << endl;
                sneakPassed = SneakAttempt(User, Enemy); // Attempt sneak check

                if (sneakPassed == true) {
                    cout << "You make it past the sleepy guard and reach the door..." << endl;
                    delete Enemy;
                    alertStatus = 1; // Sneak work, undetected
                    // Armoury
                    location = 2;
                }
                else if (sneakPassed == false) {
                    cout << "You knock over a table and wake the guard, he immediatley jumps for you." << endl;
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    alertStatus = 2; // Sneak failed, detected
                    // Alchemy lab
                    location = 3;
                }
            }
            // ========== Combat approach ========== //
            else if (eTracker == 3) {
                cout << "You attack the guard hoping he will tell you which way to go." << endl;
                //Successful combat
                Fight(User, Enemy); // Fight
                delete Enemy;
                alertStatus = 2; // Detected
                cout << "The guard point to the middle door, but before his last breath he yells. Alerting the area..." << endl;
                //Blacksmiths
                location = 1;
            }
            // ========== Save and exit ========== //
            else if (eTracker == 4) {
                saveGame(User->getName(), User->getPlayerClass(), encounter, alertStatus);
                cout << "The game has been saved." << endl;
                delete User;
                exit(0);
            }
        }
        // ========== PATH 2: Player was caught or attacked someone

        else if (alertStatus == 2) {
            Encounter21(); // Show encounter for being caught
            eTracker = playerDecision(); // Choose between middle, left and right door

            // ========== Middle door (Brute) ========== //
            if (eTracker == 1) {
                Enemy = new Brute(); // Create Brute enemy

                cout << "\nYou could probably talk your way past him." << endl;
                cout << "1)Talk your way around him\n2)Sneak your way around him\n3)Fight him" << endl;
                cin >> playerApproach; // Take players approach
                while (cin.fail() || playerApproach != 1 && playerApproach != 2 && playerApproach != 3) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "You must choose 1, 2 or 3." << endl;
                    cin >> playerApproach;
                }

                // ========== Speech outcome ========== //
                if (playerApproach == 1) {
                    cout << "You explain you are delivering a fresh supply of herbs and that you are already late." << endl;
                    speechPassed = speechAttempt(User, Enemy); // Attempt speech check


                    if (speechPassed == true) {
                        cout << "He steps to the side, but he still hasn't spoken a word. Hopefully he doesn't attack you." << endl;
                        cout << "You walk through the door." << endl;
                        delete Enemy;
                        alertStatus = 1; // Passed speech check, undetected
                        // Alchemy lab
                        location = 3;
                    }

                    else if (speechPassed == false)
                    {
                        cout << "He is silent but looks angered, he comes running towards you." << endl;
                        Fight(User, Enemy); // Start Fight
                        delete Enemy;
                        alertStatus = 2; // Failed speech, Detected
                        // Alchemy lab
                        location = 3;
                    }
                }
                // ========== Sneak outcome ========== //
                if (playerApproach == 2) {
                    sneakPassed = SneakAttempt(User, Enemy); // Attempt to sneak
                    cout << "You throw a glass bottle you found on the floor across the room." << endl;


                    if (sneakPassed == true) {
                        cout << "The brute waddles along the corridor to check it out." << endl;
                        delete Enemy;
                        alertStatus = 1; // Passed sneak, undetected
                        // Alchemy lab
                        location = 3;
                    }

                    else if (sneakPassed == false) {
                        cout << "The brute was more alert then you thought, he's sprinting towards you." << endl;
                        Fight(User, Enemy); // Start fight
                        delete Enemy;
                        alertStatus = 2; // Failed sneak, detected
                        // Alchemy lab
                        location = 3;
                    }
                }
                // ========== Combat outcome ========== //
                if (playerApproach == 3) {
                    cout << "You waste no time and dive in to cut the brute down." << endl;
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    alertStatus = 2; // Detected
                    // Alchemy lab
                    location = 3;
                }
            }
            // ========== Left door (Royal Guard) ========== //
            else if (eTracker == 2) {
                Enemy = new RoyalGuard(); // Spawn royal guard
                cout << "Will you attempt to\n1)Speak to them\n2)Sneak past them\n3)Attack them." << endl;
                cin >> playerApproach; // Take player approach
                while (cin.fail() || playerApproach != 1 && playerApproach != 2 && playerApproach != 3) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "You must choose 1, 2 or 3." << endl;
                    cin >> playerApproach;
                }

                // ========== Speech outcome ========== //
                if (playerApproach == 1) {
                    //Speech passed
                    cout << "You attempt to tell the guard you have been sent to quality check all of the armoury." << endl;
                    speechPassed = speechAttempt(User, Enemy); // Attempt speech check


                    if (speechPassed == true) {
                        cout << "Surprisingly the stern looking guard steps to the side grants entry." << endl;
                        delete Enemy;
                        alertStatus = 1; // Passed, undetected
                        //Armoury
                        location = 2;
                    }
                    //Fail you fight
                    else if (speechPassed == false) {
                        cout << "The guard immediately asks for some ID papers but since you're lying you have none. He unsheathes his sword." << endl;
                        Fight(User, Enemy); // Start a fight
                        delete Enemy;
                        alertStatus = 2; // Failed speech, detected
                        //Armoury
                        location = 2;
                    }

                }
                // ========== Sneak outcome ========== //
                else if (playerApproach == 2) {
                    cout << "This guard looks very alert. You light some draperies on fire to try to move him..." << endl;
                    sneakPassed = SneakAttempt(User, Enemy); // Attempt sneak


                    //Sneak success
                    if (sneakPassed == true) {
                        cout << "Luckily instead of waiting for another welp to stop the fire, he runs to find water." << endl;
                        delete Enemy;
                        alertStatus = 1; // Passed, undetected
                        //Armoury
                        location = 2;
                    }
                    //Fail to sneak past
                    else if (sneakPassed == false) {
                        cout << "The guard instead of looking for water instead looks for the cause, and he find you hidden. He strikes..." << endl;
                        Fight(User, Enemy); // Start a fight
                        delete Enemy;
                        alertStatus = 2; // Failed sneak, detected
                        // Armoury
                        location = 2;
                    }
                }
                // ========== Combat outcome ========== //
                else if (playerApproach == 3) {
                    cout << "This guard looks much too cunning you strike to catch him unawares." << endl;
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    alertStatus = 2; // Detected
                    //Armoury
                    location = 2;
                }
            }
            // ========== Right Door (Blacksmith)
            else if (eTracker == 3) {
                Enemy = new Blacksmith(); // Spawn blacksmith
                cout << "Sleepily the man begins to argue that no-one is going inside his workshop." << endl;
                cout << "Will you\n1)Try to convince him you are just taking inventory of stock\n2)Wait and see if he falls asleep\n3)Fight him" << endl;
                cin >> playerApproach; // Take player approach
                while (cin.fail() || playerApproach != 1 && playerApproach != 2 && playerApproach != 3 && playerApproach !=4) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "You must choose 1, 2 or 3." << endl;
                    cin >> playerApproach;
                }

                // ========== Speech Outcome ========== //
                if (playerApproach == 1) {
                    speechPassed = speechAttempt(User, Enemy); // Attempt speech check

                    if (speechPassed == true) {
                        cout << "The old man scoffs and walks away down the corridor." << endl;
                        delete Enemy;
                        alertStatus = 1; // Passed, undetected
                        location = 1;
                    }

                    else if (speechPassed == false) {
                        cout << "The smithy says 'I think I'll take inventory of my own stock thank you'. Then attacks." << endl;
                        Fight(User, Enemy); // Fight
                        delete Enemy;
                        alertStatus = 2; // Failed detected
                        // Smithy
                        location = 1;
                    }
                }
                //Sneak outcome
                if (playerApproach == 2) {
                    sneakPassed = SneakAttempt(User, Enemy);
                    //Passed Sneak
                    if (sneakPassed == true) {
                        cout << "You wait for a few minutes and he actually falls asleep." << endl;
                        delete Enemy;
                        alertStatus = 1; // Passed, undetected
                        // Smithy
                        location = 1;
                    }
                    else if (sneakPassed == false) {
                        cout << "The guard doesn't fall asleep but instead notices you watching and tries to attack." << endl;
                        Fight(User, Enemy); // Start a fight
                        delete Enemy;
                        // Smithy
                        location = 1;
                    }
                }
                //Combat outcome
                if (playerApproach == 3) {
                    cout << "He's an old man, he can't be that tough. You attack..." << endl;
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    // Smithy
                    alertStatus = 2;
                    location = 1;
                }
            }
            // ========== Save and Exit ========== //
            else if (eTracker == 4) {
                saveGame(User->getName(), User->getPlayerClass(), encounter, alertStatus);
                cout << "The game has been saved." << endl;
                delete User;
                exit(0);
            }

        }


        // Separate encounter
        encounterBreak();

        // ========== Encounter 3 chance for weapons/armour and potions ========== //

            //If they chose the smithy
        if (location == 1) {
            //Offer to pick up new weapon of leave it
            cout << "You see a weapon on the table that is clearly better than yours." << endl;
            cout << "Do you take it\n1)Yes\n2)No" << endl;
            eTracker = playerDecision(); // Take players decision
            
            //Take the sword
            if (eTracker == 1) {
                //Increase players attack
                cout << "You take the sword." << endl;
                User->increaseAttack(); // Increase players attack stat
                DEBUG("PLayer new attack stat: " << User->getAttack());
            }
            //Don't take the weapon
            else if (eTracker == 2) {
                cout << "You leave the sword and continue down the corridor." << endl;
            }
        }

        //If they chose the armoury
        if (location == 2) {
            cout << "You find some strong looking armour on the rack." << endl;
            cout << "Do you:\n1)Take it\n2)Leave it" << endl;
            eTracker = playerDecision(); // Take players decision


            //Takes the armour
            if (eTracker == 1) {
                cout << "You take the armour and it fits well." << endl;
                User->increaseArmour(); // Increase players armour stat
                DEBUG("PLayer new armour stat: " << User->getArmour());
            }
            //Leave the armour
            else if (eTracker == 2) {
                cout << "You leave the armour and continue down the hallway." << endl;
            }

        }

        //If they chose the alchemy lab
        if (location == 3) {
            cout << "There are some health potion on the table." << endl;
            cout << "Will you:\n1)Take them\n2)Leave them" << endl;
            eTracker = playerDecision(); // Take players decision


            //Takes them
            if (eTracker == 1) {
                cout << "You take 2 health potions and store them in your bag." << endl;
                User->addPotion(2); // Add potions to player inventory
            }
            else {
                cout << "You leave the potions alone and continue down the corridoor." << endl;
            }
        }

        // ========== Save and Exit ========== //
        else if (eTracker == 4) {
            saveGame(User->getName(), User->getPlayerClass(), encounter, alertStatus);
            cout << "The game has been saved." << endl;
            delete User;
            exit(0);
        }
    }
    // Separate encounters
    encounterBreak();


    // ========== Final Encounter ========== //
    // ========== Setting encounter level ========== //
    encounter = 3;

    // ========== Checking encounter ========== //
    if (encounter == 3) {


        switch (alertStatus)
        {
        case 1: //Compund on low alert
            Encounter41(); // Read undetected scenario

            Enemy = new unawarebanditLeader(); // Spawn Boss
            playerApproach = playerDecision(); // Take players approach

            // ========== Combat outcome ========== //
            if (playerApproach == 1) {
                Fight(User, Enemy); // Start a fight
                delete Enemy;
                cout << "You have taken the key from who was the leader of the thieves who stole it." << endl;
                cout << "You open the lockbox and take the chalice. The quest is finally complete." << endl;
            }

            // ========== Speech outcome ========== //
            else if (playerApproach == 2) {
                cout << "You lie and tell him the compound is surrounded by a overwhelming force." << endl;
                speechPassed = speechAttempt(User, Enemy); // Attempt speech attempt

                //Passed speech
                if (speechPassed == true) {
                    cout << "After a few minutes of consideration he succumbs and releases the chalice to you. The quest is finally complete." << endl;
                    delete Enemy;
                }
                //Failed speech
                else if (speechPassed == false) {
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    cout << "You have taken the key from who was the leader of the thieves who stole it." << endl;
                    cout << "You open the lockbox and take the chalice. The quest is finally complete." << endl;
                }
            }

            // ========== Sneak outcome ========== //
            if (playerApproach == 3) {
                cout << "You throw caution to the wind and attempt to swipe the chalice from him..." << endl;
                sneakPassed = SneakAttempt(User, Enemy); // ttempt sneak check

                // Passed sneak check
                if (sneakPassed == true) {
                    cout << "You grab the chalice without anyone noticing." << endl;
                    cout << "Yout stroll out of the compund like it was your own house. You have completed your quest." << endl;
                    delete Enemy;
                }
                // Failed sneack check
                else if (sneakPassed == false) {
                    cout << "As your hand reaches the chalice you pull back, narrowly missing his sword swipe. He caught you and attacks." << endl;
                    Fight(User, Enemy);
                    delete Enemy;
                    cout << "You finally take the chalice and leave the compound. Completing your quest and earning your reward." << endl;
                }
            }

            // ========== Save and Exit ========== //
            else if (playerApproach == 4) {
                saveGame(User->getName(), User->getPlayerClass(), encounter, alertStatus);
                cout << "The game has been saved." << endl;
                delete User;
                delete Enemy;
                exit(0);
            }
            break;

            // ========== Compound on high alert ========== //
        case 2:
            Encounter42(); // Read high alert scenario

            Enemy = new awarebanditLeader(); // Spawn boss

            playerApproach = playerDecision(); // Take player approach

            // ========== Combat outcome ========== //
            if (playerApproach == 1) {
                Fight(User, Enemy); // Start a fight
                delete Enemy;
                cout << "You have taken the key from who was the leader of the thieves who stole it." << endl;
                cout << "You open the lockbox and take the chalice. The quest is finally complete." << endl;
            }

            // ========== Speech outcome ========== //
            else if (playerApproach == 2) {
                cout << "You lie and tell him the compound is surrounded by a overwhelming force." << endl;
                speechPassed = speechAttempt(User, Enemy); // Attempt speech check

                //Passed speech
                if (speechPassed == true) {
                    cout << "\nAfter a few minutes of consideration he succumbs and releases the chalice to you. The quest is finally complete." << endl;
                    delete Enemy;
                }
                //Failed speech
                else if (speechPassed == false) {
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    cout << "You have taken the key from who was the leader of the thieves who stole it." << endl;
                    cout << "You open the lockbox and take the chalice. The quest is finally complete." << endl;
                }
            }

            // ========== Sneak outcome ========== //
            if (playerApproach == 3) {
                cout << "You throw caution to the wind and attempt to swipe the chalice from him..." << endl;
                sneakPassed = SneakAttempt(User, Enemy); // Attempt sneak check


                //Sneak passed
                if (sneakPassed == true) {
                    cout << "You grab the chalice without anyone noticing." << endl;
                    cout << "Yout stroll out of the compund like it was your own house. You have completed your quest." << endl;
                    delete Enemy;
                }
                //Sneak failed
                else if (sneakPassed == false) {
                    cout << "As your hand reaches the chalice you pull back, narrowly missing his sword swipe. He caught you and attacks." << endl;
                    Fight(User, Enemy); // Start a fight
                    delete Enemy;
                    cout << "You finally take the chalice and leave the compound. Completing your quest and earning your reward." << endl;
                }
            }

            // ========== Save and Exit ========== //
            else if (playerApproach == 4) {
                saveGame(User->getName(), User->getPlayerClass(), encounter, alertStatus);
                cout << "The game has been saved." << endl;
                delete User;
                exit(0);
            }
            break;
        }
    }
    else {
        cout << "You shouldn't be here..." << endl;
    }
}
