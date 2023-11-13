#pragma once
#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>   

using namespace std;

//class Enemy;


class Entity {
protected:
    string name;
    int strength;
    int defense;
    int maxHP;
    int currentHP;
    int maxMP;
    int currentMP;
    bool isGuarding;
    string specialMoveName;

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
        int damage = (rand() % 20) + (strength - 10);  // Random damage within a certain range
        cout << getName() << " is attacking " << target.getName() << ".\n";
        target.takeDamage(damage);
        //system("pause");
    }

    // Guard method
    void guard() {
        isGuarding = true;
        cout << getName() << " is guarding.\n";

        //system("pause");
    }

    // Drop Guard method
    void dropGuard() {
        isGuarding = false;
    }

    // Take Damage method
    void takeDamage(int damage) {
        int finalDamage = max(1, damage - (defense / 2));
        if (isGuarding) {
            finalDamage = max(1, finalDamage / 2);  // Guard reduces damage by half
            dropGuard(); // The timing of when guard is dropped is handled by main
        }

        currentHP = max(0, currentHP - finalDamage);

        cout << getName() << " took " << finalDamage << " damage.\n";
    }

    // Damage from a special move, ignoring defense and guard
    void takeSpecialDamage(int damage) {
        currentHP = max(0, currentHP - damage);
        cout << name << " took " << damage << " damage." << endl;
    }

    // Special Move method



    // Check if defeated method
    const bool isDefeated() const {
        return currentHP < 1;
    }
};

class Enemy;

class Player : public Entity{
  public:
  Player(): Entity("Human", 100, 100, 500, 500){
    level = 1;
    setName(); // for this to work, the Entity member variables need to set to protected
    chooseType();
  };

  void setName(){
    string Name;
    nameset = true;
    while (nameset) {
        cout << "Please enter your name: ";
        getline(cin, Name);
        if (Name.length() == 0) {
            cout << "Name should be at least one character long." << endl;
        }
        else if (Name.length() > 20) { // Change 20 to your desired maximum length
            cout << "Name should be less than 20 characters." << endl;
        }
        else {
            this->name = Name;
            nameset = false;
            break;
        }
    } 
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
      //system("pause");
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

  void specialMove(Enemy &enemy);/*{
    cout << specialMoveName << endl;
    enemy.takeSpecialDamage();
  }*/

  void takeSpecialDamage(){
    this->currentHP -= 50;
    cout << this->name << " took 50 damage";
  }


  private:
    int level;
    string type;
    int typeNumber;
    int healCount;
    bool nameset;
};


class Enemy : public Entity{
  public:
  Enemy(string Name): Entity(Name, 100, 100, 500, 500){
    healCount = 1;
    chooseType();
    decisionMade = false;
  };

  Enemy() : Entity("Enemy", 100, 100, 500, 500) {
    healCount = 1;
    chooseType();
    decisionMade = false;
  }

  void takeSpecialDamage(){
    cout << this->name << " took 100 damage" << endl;
    this->currentHP -= 100;
  }

  void makeDecision(Player &player){
    srand(time(0));
    action = (rand() % 4) + 1;
    while(decisionMade == false){
        if (action == 1){
          this->attack(player);
          decisionMade = true;
        }
        else if(action == 2){
          this->guard();
          decisionMade = true;
        }
        else if(action == 3){
          this-> heal();
          decisionMade = true;
        }
        else {
          if (this->getCurrentMP() >= 50){
            this->specialMove(player);
            this->currentMP -= 25;
            decisionMade = true;
          }
          else{
            continue;
          }
    
        }
    }
      decisionMade = false;
  }

  void specialMove(Player &player){
    cout << specialMoveName << endl;
    player.takeSpecialDamage();
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
      cout << "\n";
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
      cout << "\n";
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
      cout << "\n";
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

  protected:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;
  string specialMoveName; // maybe add this to the entity class and cout the spesial move name before calling it?
  bool decisionMade;

};

void Player::specialMove(Enemy &enemy){
    cout << specialMoveName << endl;
    enemy.takeSpecialDamage();
}

class Rat : public Enemy{
  public:
  Rat(): Enemy("Rat"){
    healCount = 1;
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 4) + 1;
    while(decisionMade == false){
        if (action == 1){
          this->attack(player);
          decisionMade = true;
        }
        else if(action == 2){
          this->guard();
          decisionMade = true;
        }
        else if(action == 3){
          this-> heal();
          decisionMade = true;
        }
        else {
          if (this->getCurrentMP() >= 50){
            this->specialMove(player);
            this->currentMP -= 25;
            decisionMade = true;
          }
          else{
            continue;
          }
        }
    }
    decisionMade = false;
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

  void specialMove(Entity &target) {
    cout << getName() << " uses " << specialMoveName << "!" << endl;
    int damage = (rand() % strength) * 2;  // Random damage within a certain range
    target.takeSpecialDamage(damage);
      //system("pause");
  }  

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;

};

class Lizard : public Enemy{
  public:
  Lizard(): Enemy("Lizard"){
    healCount = 1;
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 4) + 1;
    while(decisionMade == false){
        if (action == 1){
          this->attack(player);
          decisionMade = true;
        }
        else if(action == 2){
          this->guard();
          decisionMade = true;
        }
        else if(action == 3){
          this-> heal();
          decisionMade = true;
        }
        else {
          if (this->getCurrentMP() >= 50){
            this->specialMove(player);
            this->currentMP -= 25;
            decisionMade = true;
          }
          else{
            continue;
          }
        }
    }
    decisionMade = false;
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

  void specialMove(Entity& target) {
    cout << name << " uses " << specialMoveName << "!" << endl;
    currentHP += 100;
      //system("pause");
  }

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;

};

class Wolf : public Enemy{
  public:
  Wolf(): Enemy("Wolf"){
    healCount = 1;
  };

  void makeDecision(Player &player){
    srand(time(0)); 
    action = (rand() % 4) + 1;
    while(decisionMade == false){
        if (action == 1){
          this->attack(player);
          decisionMade = true;
        }
        else if(action == 2){
          this->guard();
          decisionMade = true;
        }
        else if(action == 3){
          this-> heal();
          decisionMade = true;
        }
        else {
          if (this->getCurrentMP() >= 50){
            this->specialMove(player);
            this->currentMP -= 50;
            decisionMade = true;
          }
          else{
            continue;
          }
        }
    }
    decisionMade = false;
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

  void specialMove(Entity& target) {
    if (strengthBonus <= 3) {
        cout << name << " uses " << specialMoveName << "!" << endl;
        strengthBonus += 1;
        strength += 50;
    }
    else {
        cout << name << " bristles with anger." << endl;
    }
      //system("pause");
  }

  private:
  int level;
  string type;
  int typeNumber;
  int healCount;
  int action;
  int strengthBonus;

};

class gamePlay{
  public:
  gamePlay(Player &Player, Enemy &Enemy){
    //player = Player;
    //enemy = Enemy;
    keepPlaying = true;
    while(keepPlaying){
      playerTurn(Player, Enemy);
      enemyTurn(Player, Enemy);
      if (Player.getCurrentHP() <= 0 || Enemy.getCurrentHP() <= 0){
        keepPlaying = false;
      }
    }
    playerHealth = Player.getCurrentHP();
    enemyHealth = Enemy.getCurrentHP();
    if (playerHealth > enemyHealth){
      cout << "\n\n";
      cout << Player.getName() << "Wins!"<< endl;
    }
    else if (enemyHealth > playerHealth){
      cout << "\n\n";
      cout << Enemy.getName() << "Wins!"<< endl;
    }
  }

  void playerTurn(Player &player, Enemy &enemy){
    cout << "\n\n";
    cout << "What do you want to do: " << endl;
    cout << "1. Attack"<<endl;
    cout << "2. Guard"<<endl;
    cout << "3. Heal"<<endl;
    cout << "4. Special Attack"<<endl;
    cout << "\n\n";
    cin >> playerChoice;
    cout << "\n\n";
    if (playerChoice == 1){
      player.attack(enemy);
    }
    else if(playerChoice == 2){
      player.guard();
    }
    else if(playerChoice == 3){
      player.heal();
    }
    else if(playerChoice == 4){
      player.specialMove(enemy);
    }
  }

  void enemyTurn(Player &player, Enemy &enemy){
    enemy.makeDecision(player);
  }


private:
  //Player player;
  //Enemy enemy;
  int playerChoice;
  bool keepPlaying;
  int playerHealth;
  int enemyHealth;
};