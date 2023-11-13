#include <iostream>
#include <string>
#include "EntityClass.h"
#include "GlobalFunctions.h"
// FIXME: Include relevant headers once created

using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>   
#include <typeinfo> 
#include <time.h> 

using namespace std;

/* class Entity {
protected:
  string name;
  int strength;
  int defense;
  int maxHP;
  int currentHP;
  int maxMP;
  int currentMP;
  bool isGuarding;

public:
  Entity(string Name, int Strength, int Defense, int MaxHP, int MaxMP)
      : name(Name), strength(Strength), defense(Defense), maxHP(MaxHP), currentHP(MaxHP),
      maxMP(MaxMP), currentMP(MaxMP), isGuarding(false) {}
  const string getName() const {
      return name;
  }

  const int getMaxHP() const {
      return maxHP;
  }

  const int getCurrentHP() const {
      return currentHP;
  }

  const int getMaxMP() const {
      return maxMP;
  }

  const int getCurrentMP() const {
      return currentMP;
  }

  // Attack method
  void attack(Entity& target) {
      int damage = rand() % strength + 1;  // Random damage within a certain range
      cout << getName() << " is attacking " << target.getName() << ".\n";
      target.takeDamage(damage);
  }


  // Guard method
  void guard() {
      isGuarding = true;
      cout << getName() << " is guarding.\n";
  }

  // Drop Guard method
  void dropGuard() {
      isGuarding = false;
  }

  // Take Damage method
  void takeDamage(int damage) {
      int finalDamage = max(1, damage - defense);
      if (isGuarding) {
          finalDamage = max(1, finalDamage / 2);  // Guard reduces damage by half
          dropGuard();
      }

      currentHP = max(0, currentHP - finalDamage);

      cout << getName() << " took " << finalDamage << " damage.\n";
  }

  // Special Move method
  virtual void specialMove(Entity& target) {
  }

  // Check if defeated method
  const bool isDefeated() const {
      return currentHP < 1;
  }
};


class Player : public Entity{
  public:
  Player(): Entity("Human", 100, 100, 500, 500){
    level = 1;
    setName(); // for this to work, the Entity member variables need to set to protected
    chooseType();
  };

  void setName(){
    cout << "Enter name: " << endl;
    cin >> this->name;
  }

  void chooseType(){
    while(typeNumber != 1 && typeNumber != 2 && typeNumber != 3){
      cout << "Choose your bloodline: " << endl;
      cout << "1: Uchiha" << endl;
      cout << "2: Saiyan" << endl;
      cout << "3: Jedi" << endl;
      cin >> typeNumber;
      cout << "\n\n";
      if (typeNumber != 1 && typeNumber != 2 && typeNumber != 3){
        cout << "Please enter 1, 2 or 3" << endl;
      }
    }
    if (typeNumber == 2){ // Saiyan
      cout << "Saiyan warrior...\n" << endl;
      this->type = "Saiyan";
      this->specialMoveName = "Spirit bomb!";
      this->strength += 100;
      this->defense += 25;
      this->maxHP += 50;
      this->maxMP += 80;
      this->currentHP += 50;
      this->currentMP += 80;

      cout << "Your stats are: " << endl;
      cout << "HP: " << this->getMaxHP() << endl;
      cout << "MP: " << this->getMaxMP() << endl;
      cout << "Strength: " << this->getStrengthLevel() << endl;
      cout << "Defense: " << this->getDefenseLevel() << endl;

    }
    else if(typeNumber == 1){ // Uchiha
      cout << "Uchiha...\n" << endl;
      this->type = "Uchiha";
      this->specialMoveName = "Amaterasu!";
      this->strength += 70;
      this->defense += 100;
      this->maxHP += 48;
      this->maxMP += 72;
      this->currentHP += 48;
      this->currentMP += 72;
      cout << "Your stats are: " << endl;
      cout << "HP: " << this->getMaxHP() << endl;
      cout << "MP: " << this->getMaxMP() << endl;
      cout << "Strength: " << this->getStrengthLevel() << endl;
      cout << "Defense: " << this->getDefenseLevel() << endl;
    }
    else{ // Jedi
      cout << "May the force be with you...\n" << endl;
      this->type = "Jedi";
      this->specialMoveName = "Mind Control!";
      this->strength += 70;
      this->defense += 75;
      this->maxHP += 30;
      this->maxMP += 100;
      this->currentHP += 30;
      this->currentMP += 100;
      cout << "Your stats are: " << endl;
      cout << "HP: " << this->getMaxHP() << endl;
      cout << "MP: " << this->getMaxMP() << endl;
      cout << "Strength: " << this->getStrengthLevel() << endl;
      cout << "Defense: " << this->getDefenseLevel() << endl;
    }
  }

  int getLevel(){
    return level;
  }

  void levelUp(){ // when player levels up, potential stats like maxHP, maxMP are all increased by 50; What about in game stats?
    level += 1;
    this->maxHP += 50;
    this->maxMP += 50;
    this->strength += 50;
    this->defense += 50;
  }

  void heal(){
    if (healCount > 0){
      int currentHealth = this->getMaxHP();
      this->currentHP = currentHealth;
      int currentMana = this->getMaxMP();
      this->currentMP = currentMana;
    }
  }

  int getStrengthLevel(){
    return this->strength;
  }

  int getDefenseLevel(){
    return this->defense;
  }


  private:
    int level;
    string type;
    int typeNumber;
    int healCount;
    string specialMoveName; // maybe add this to the entity class and cout the spesial move name before calling it?
};


class Enemy : public Entity{
  public:
  Enemy(): Entity("Enemy", 100, 100, 500, 500){
    healCount = 1;
    chooseType();
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 5) + 1;

    if (action == 1){
      this->attack(player);
    }
    else if(action == 2){
      this->guard();
    }
    else if(action == 3){
      this->dropGuard();
    }
    else if(action == 4){
      this-> heal();
    }
    else {
      if (this->getCurrentMP() > 50){
        this->specialMove(player);
        this->currentMP -= 25;
      }
      else{
        cout << "You do not have enough MP." << endl;
      }

    }
  }

  void chooseType(){
    srand(time(0)); 
    typeNumber = (rand() % 3) + 1;

    if (typeNumber == 2){ // Thanos
      this->name = "Thanos";
      this->specialMoveName = "Finger snap!";
      this->strength += 100;
      this->defense += 25;
      this->maxHP += 50;
      this->maxMP += 80;
      this->currentHP += 50;
      this->currentMP += 80;
      cout << "You are fighting: " << this->name << endl;
    }
    else if(typeNumber == 1){ // The Matrix
      this->name = "The Matrix";
      this->specialMoveName = "Propaganda!";
      this->strength += 70;
      this->defense += 100;
      this->maxHP += 48;
      this->maxMP += 72;
      this->currentHP += 48;
      this->currentMP += 72;
      cout << "You are fighting: " << this->name << endl;
    }
    else{ // Skynet
      this->name = "Skynet";
      this->specialMoveName = "Deploy Terminator!";
      this->strength += 70;
      this->defense += 75;
      this->maxHP += 30;
      this->maxMP += 100;
      this->currentHP += 30;
      this->currentMP += 100;
      cout << "You are fighting: " << this->name << endl;
    }
  }

  void heal(){
    if (healCount > 0){
      int currentHealth = this->getMaxHP();
      this->currentHP = currentHealth;
    }
  }

  int getStrengthLevel(){
    return this->strength;
  }

  int getDefenseLevel(){
    return this->defense;
  }

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;
  string specialMoveName; // maybe add this to the entity class and cout the spesial move name before calling it?

};

class Rat : public Entity{
  public:
  Rat(): Entity("Rat", 100, 100, 500, 500){
    healCount = 1;
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 5) + 1;

    if (action == 1){
      this->attack(player);
    }
    else if(action == 2){
      this->guard();
    }
    else if(action == 3){
      this->dropGuard();
    }
    else if(action == 4){
      this-> heal();
    }
    else {
      if (this->getCurrentMP() > 50){
        this->specialMove(player);
        this->currentMP -= 25;
      }
      else{
        cout << "You do not have enough MP." << endl;
      }

    }
  }

  void heal(){
    if (healCount > 0){
      int currentHealth = this->getMaxHP();
      this->currentHP = currentHealth;
    }
  }

  int getStrengthLevel(){
    return this->strength;
  }

  int getDefenseLevel(){
    return this->defense;
  }

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;
  string specialMoveName; // maybe add this to the entity class and cout the spesial move name before calling it?

};

class Lizard : public Entity{
  public:
  Lizard(): Entity("Lizard", 100, 100, 500, 500){
    healCount = 1;
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 5) + 1;

    if (action == 1){
      this->attack(player);
    }
    else if(action == 2){
      this->guard();
    }
    else if(action == 3){
      this->dropGuard();
    }
    else if(action == 4){
      this-> heal();
    }
    else {
      if (this->getCurrentMP() > 50){
        this->specialMove(player);
        this->currentMP -= 25;
      }
      else{
        cout << "You do not have enough MP." << endl;
      }

    }
  }

  void heal(){
    if (healCount > 0){
      int currentHealth = this->getMaxHP();
      this->currentHP = currentHealth;
    }
  }

  int getStrengthLevel(){
    return this->strength;
  }

  int getDefenseLevel(){
    return this->defense;
  }

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;
  string specialMoveName; // maybe add this to the entity class and cout the spesial move name before calling it?

};

class Wolf : public Entity{
  public:
  Wolf(): Entity("Rat", 100, 100, 500, 500){
    healCount = 1;
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 5) + 1;

    if (action == 1){
      this->attack(player);
    }
    else if(action == 2){
      this->guard();
    }
    else if(action == 3){
      this->dropGuard();
    }
    else if(action == 4){
      this-> heal();
    }
    else {
      if (this->getCurrentMP() > 50){
        this->specialMove(player);
        this->currentMP -= 25;
      }
      else{
        cout << "You do not have enough MP." << endl;
      }

    }
  }

  void heal(){
    if (healCount > 0){
      int currentHealth = this->getMaxHP();
      this->currentHP = currentHealth;
    }
  }

  int getStrengthLevel(){
    return this->strength;
  }

  int getDefenseLevel(){
    return this->defense;
  }

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;
  string specialMoveName; // maybe add this to the entity class and cout the spesial move name before calling it?

};


int main(){
  // Game-wide variables
  Enemy nullEnemy; // The null enemy is meant to fill slots in the field[] array that contain no enemy
  Enemy field[] = {nullEnemy, nullEnemy, nullEnemy}; // The field stores all the enemies currently in play
  Wolf finalBoss; // Sample Enemy type - Enemy subclass names are subject to change
  char currCommand; // The most recent command entered by the player
  int currIndex; // The most recent enemy index entered by the player

  // Player initialization
  Player player; // The Player constructor handles stat assignments for the player

  // Initialize the game state
  callRandomEncounter(field);

  // Gameplay loop
  while (not(player.isDefeated()) && not(finalBoss.isDefeated())) { // Game ends when either the player is knocked out or the final boss is defeated
    // Check if the battle is ongoing
    if (isBattleOver(field)) {
      winBattle(player);
      // The final battle begins when the player reaches level 5
      if (player.getLevel() >= 5) {
        callFinalBoss(field, finalBoss);
      }
      // If the player is not at level 5, set up a random battle
      else {
        callRandomEncounter(field);
      }
    }
    
    // Begin turn
    printTurnStatus(player, field);
    player.dropGuard(); // Gets rid of any guard bonus lingering from previous turn
    currCommand = validatePlayerCommand(player); // validatePlayerCommand handles receiving a valid command from the player

    // If command is to attack
    if (currCommand == 'a') {
      currIndex = validateEnemyIndex(field); // validateEnemyIndex handles targeting
      player.attack(field[currIndex]);
      // If the most recent enemy attacked is now defeated
      if (field[currIndex].isDefeated()) {
        updateField(field, nullEnemy, currIndex); // Remove the defeated enemy from play
      }
    }

    // If command is to guard
    else if (currCommand == 'g') {
      player.guard();
    }

    // If command is to use special attack
    else if (currCommand == 's') {
      currIndex = validateEnemyIndex(field);
      player.specialMove(field[currIndex]);
      if (field[currIndex].isDefeated()) {
        updateField(field, nullEnemy, currIndex);
      }
    }

    // Begin enemy turn
    for (int i = 0; i < 3; i++) {
      // If there is no enemy in the current slot
      if (field[i].getMaxHP() == 0) { // This should work since no enemy other than the null enemy should have a max HP of 0
        continue;
      }
      // Otherwise, take the enemy's turn
      else {
        field[i].dropGuard(); // This logic is placed here to make sure an enemy that guards is still guarding during the player's turn
        field[i].makeDecision(player); // makeDecision handles logic for enemy behavior
      }
    }
  }

  // End message
  if (player.isDefeated()) { // If the player lost
    cout << "YOU HAVE DIED" << endl << endl;
    cout << "TRY AGAIN" << endl;
  }
  else if (finalBoss.isDefeated()) { // If the player won
    cout << "YOU WIN!" << endl;
  }

  return 0;
}
*/

int main(){
  Player player;
  Enemy enemy;

  gamePlay(player, enemy);

  return 0;
}