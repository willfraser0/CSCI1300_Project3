#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include "Party.h"
#include "Player.h"

using namespace std;

class Monster
{
private:

    string monster_name;
    int weapon_strength;
    int challenge_rating;
    int weapon_difference;
    int amount_armor;
    int random1;
    int random2;
    int rooms_cleared;
    
    vector<Monster> monster_list;
    
    Monster spawned_monster;




 

public:
    Monster();
    Monster(string monster_name, int challenge_rating);

    int battleCalculation();

    string getMonsterName();
    int getMonsterRating();

    string getFirstMonsterName();
    int getFirstMonsterRating();

    void setMonsterName(string input_name);
    void setMonsterRating(int input_rating);

    void killFirstMonster();

    void populateMonsters();

    Monster spawnMonster();

    Monster Getmonster(int rooms_cleared);

    void fightDialogue();

    void surrenderDialogue();
    
    int setRoomsCleared(int rooms_cleared);
    

    int getWeaponStrength();
    
    int getWeaponDifference();

    
    int getAmountArmor();

    int getRandomNumber();

    void splitMonster(string input_string, char separator, string arr[], int arr_size);


    
   
};

#endif
