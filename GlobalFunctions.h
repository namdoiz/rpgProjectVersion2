#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "EntityClass.h"

using namespace std;
/*
void callFinalBoss(Enemy field[3], Enemy finalBoss) {
    // Placing the final boss on the field
    field[0] = finalBoss;

    // Displaying the foreboding message
    cout << "The final boss, " << finalBoss.getName() << ", emerges from the shadows!" << endl;
}

void callRandomEncounter(Enemy field[3]) {
    srand(time(0)); // Seed the random number generator with current time

    Rat rat1, rat2;
    Lizard lizard1, lizard2;
    Enemy nullEnemy;

    // Predefined enemy sets for different encounters
    Enemy encounters[3][3] = {
        {rat1, rat2, nullEnemy},
        {lizard1, lizard2, nullEnemy},
        {rat1, lizard1, rat2}
        // Add more encounters as needed
    };

    int encounterIndex = rand() % 3; // Randomly select an encounter

    // Place the selected enemies in the field
    for (int i = 0; i < 3; ++i) {
        field[i] = encounters[encounterIndex][i];
    }

    // Display encounter message
    cout << "A";
    for (int i = 0; i < 3; ++i) {
        cout << " " << encounters[encounterIndex][i].getName();
        if (i < 2) {
            if (!(encounters[i + 1]->getName().empty())) {
                cout << " and";
            }
        }
    }
    cout << " appear!" << endl;
}

const bool isBattleOver(Enemy field[3]) {
    for (int i = 0; i < 3; ++i) {
        if (!field[i].getName().empty()) {
            return false; // If any enemy is present, the battle isn't over
        }
    }
    return true; // If all enemies are null, the battle is over
}

const void printTurnStatus(Player player, Enemy field[3]) {
    system("cls");
    // Display player status
    cout << "Player Status: " << player.getName() << ", Health: " << player.getCurrentHP() << ", MP: " << player.getCurrentMP() << endl;

    // Display enemy positions
    for (int i = 0; i < 3; ++i) {
        if (!field[i].getName().empty()) {
            cout << "Enemy " << i + 1 << ": " << field[i].getName() << ", Health: " << field[i].getCurrentHP() << endl;
        }
        else {
            cout << "No enemy at index " << i + 1 << endl;
        }
    }
}

void updateField(Enemy field[3], Enemy nullEnemy, int index) {
    // Locate the defeated enemy (for example, let's assume it's the second enemy in the field)
    field[index] = nullEnemy; // Set the defeated enemy to the nullEnemy placeholder

    // Rearrange the enemies to maintain continuity
    for (int i = 1; i < 3; ++i) {
        if (field[i].getName().empty()) {
            // Swap the empty slot with the next valid enemy, if any
            int j = i + 1;
            while (j < 3 && field[j].getName().empty()) {
                ++j;
            }
            if (j < 3) {
                field[i] = field[j];
                field[j] = nullEnemy;
            }
        }
    }
}

int validateEnemyIndex(Enemy field[3]) {
    int index;
    while (true) {
        cout << "Enter the index of the enemy (1, 2, or 3): ";
        cin >> index;

        if (index < 1 || index > 3) {
            cout << "Invalid index. Please enter a valid index (1, 2, or 3)." << endl;
        }
        else if (field[index - 1].getName().empty()) { // Checking if the enemy at the given index is empty (not present)
            cout << "No enemy at this index. Please select another index." << endl;
        }
        else {
            return index - 1; // Adjusting the index to match the array index
        }
    }
}

char validatePlayerCommand(Player player) {
    char command;
    while (true) {
        cout << "Please enter your command (a: attack, g: guard, s: special): ";
        cin >> command;

        if (command == 's' && player.getCurrentMP() < 10) { // Assuming special move costs 10 MP
            cout << "Not enough MP for special move." << endl;
        }
        else if (command != 'a' && command != 'g' && command != 's') {
            cout << "Invalid command. Please enter a valid command." << endl;
        }
        else {
            return command;
        }
    }
}
*/
/* string validatePlayerName() {
    string name;
    while (true) {
        cout << "Please enter your name: ";
        getline(cin, name);

        if (name.length() == 0) {
            cout << "Name should be at least one character long." << endl;
        }
        else if (name.length() > 20) { // Change 20 to your desired maximum length
            cout << "Name should be less than 20 characters." << endl;
        }
        else {
            return name;
        }
    }
} */

/* void winBattle(Player& player) { // 
    // Display victory message
    cout << "Victory! " << player.getName() << " wins the battle!" << endl;

    // Level up the player
    player.experience += 100; // Assuming the player gains 100 experience points after a battle

    if (player.experience >= 1000) {
        player.level++; // Level up if experience reaches a certain threshold (e.g., 1000)
        player.experience = 0; // Reset experience points after leveling up
    }
    cout << player.name << " leveled up to level " << player.level << "!" << endl;
} */
/*
void winBattle(Player& player) {
    // Display victory message
    cout << "Victory! " << player.getName() << " wins the battle!" << endl;

    // Level up the player
    player.levelUp();
    
    cout << player.getName() << " leveled up to level " << player.getLevel() << "!" << endl;
    system("pause");
}
*/