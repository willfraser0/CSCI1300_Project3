#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "Party.h"

Party::Party() {
    gold_coins = 100;
    ingredients = 0; 
}

void Party::addMember(string member_name) {
    Player new_player = Player(member_name);
    party_members.push_back(new_player);
}

void Party::removeMember(int member_id) {
    party_members.erase(party_members.begin() + member_id - 1);
}

Player Party::Member(int member_id) {
    return party_members[member_id];
}

void Party::setGold(int input_gold) {
    gold_coins = input_gold;
}

void Party::addGold(int input_gold) {
    gold_coins += input_gold;
}

int Party::getGold() {
    return gold_coins;
}

void Party::setIngredients(int input_ingredients) {
    ingredients = input_ingredients;
}

void Party::addIngredients(int input_ingredients) {
    ingredients += input_ingredients;
}

int Party::getIngredients() {
    return ingredients;
}

void Party::displayInventory() {

    int armor = 0;
    int weapons[5] = {0};

    for (int i = 0; i < 5; i++) {
        armor += party_members[i].getArmor();
    }

    for (int i = 0; i < 5; i++) {
        switch (party_members[i].getWeaponType()) {
            case 'C':
                weapons[0] ++;
            break;
            case 'S':
                weapons[1] ++;
            break;
            case 'R':
                weapons[2] ++;
            break;
            case 'B':
                weapons[3] ++;
            break;
            case 'L':
                weapons[4] ++;
            break;
        }
    }

    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold_coins << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: " << cookware[0] << " | F: " << cookware[1] << " | C: " << cookware[2] << endl;
    cout << "| Weapons     | C: " << weapons[0] << " | S: " << weapons[1] << " | R: " << weapons[2] << " | B: " << weapons[3] << " | L: " << weapons[4] << endl;
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasures[0] << " | N: " << treasures[1] << " | B: " << treasures[2] << " | C: " << treasures[3] << " | G: " << treasures[4] << endl << endl;
}

void Party::cook() {
    system("clear");
    cout << "Time to cook" << endl;
    
}

void Party::addCookware(char input_cookware) {
    switch (input_cookware) {
        case 'P':
            cookware[0] ++;
        break;
        case 'F':
            cookware[1] ++;
        break;
        case 'C':
            cookware[2] ++;
        break;
}}

void Party::addTreasure(char input_treasure) {
    switch (input_treasure) {
        case 'R':
            treasures[0] ++;
        break;
        case 'N':
            treasures[1] ++;
        break;
        case 'B':
            treasures[2] ++;
        break;
        case 'C':
            treasures[3] ++;
        break;
        case 'G':
            treasures[4] ++;
        break;
}}

void Party::addWeapons(char weapon_type, int amount)
{
    switch (weapon_type)
    {
    case 'C':
        weapons[0] += amount;
        break;
    case 'S':
        weapons[1] += amount;
        break;
    case 'R':
        weapons[2] += amount;
        break;
    case 'B':
        weapons[3] += amount;
        break;
    case 'L':
        weapons[4] += amount;
        break;
    }
}

void Party::addArmor(int armor_amount)
{
    if (armor[0] = 0 && armor_amount > 0)
    {
        armor[0] = 1;
        armor_amount--;
    }
    else if (armor[1] = 0 && armor_amount > 0)
    {
        armor[1] = 1;
        armor_amount--;
    }
    else if (armor[2] = 0 && armor_amount > 0)
    {
        armor[2] = 1;
        armor_amount--;
    }
    else if (armor[3] = 0 && armor_amount > 0)
    {
        armor[3] = 1;
        armor_amount--;
    }
    else if (armor[4] = 0 && armor_amount > 0)
    {
        armor[4] = 1;
        armor_amount--;
    }
}

int Party::getArmor()
{
    int amount_armor = 0;
    for (int member_id = 0; member_id < party_members.size(); member_id++)
    {
        if (party_members[member_id] == 1)
        {
            amount_armor++;
        }
    }
    return amount_armor;
}

int Party::getWeaponStrength()
{
    int weapon_strength = (weapons[0] + weapons[1] + 1(weapons[2]) + 2(weapons[3]) + 3(weapons[4]));
    return weapon_strength;
}

int Party::getWeaponDifference()
{
    int weapon_difference = 0;
    
    if (weapons[0] != 0 && weapons[1] != 0 && weapons[2] != 0 &&  weapons[3] != 0 && weapons[4] != 0)
    {
        weapon_difference=4;
    }
    
    return weapon_difference;
}

string Party::getLastMemberName()
{
    return party_members.back().getPlayerName();
}
