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




 

public:
    Monster();
    Monster(string monster_name, int challenge_rating);

    string getMonsterName();
    string setMonsterName();

    int getMonsterRating();
    int setMonsterRating();

    Monster Getmonster(int rooms_cleared);

    void KillMonster(int monster_id);

    void populateMonsters();

    int setRoomsCleared(int rooms_cleared);
    void fightDialogue();

    int getWeaponStrength();
    int getChallengeRating();
    int getWeaponDifference();
    int getAmountArmor();

    int getRandomNumber();

    void splitMonster();


    
   
};

#endif
