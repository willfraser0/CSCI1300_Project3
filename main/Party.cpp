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

void Party::addCookware(char input_cookware, int amount) {
    for (int i = 0; i < amount; i++) {
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
}}}

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

void Party::sellTreasure() {
    cout << "treasures are sold" << endl;
}

int Party::getRoomsCleared() {
    return rooms_cleared;
}

void Party::addWeapons(char input_weapon, int member) {
    weapons[member] = input_weapon;
}

void Party::addArmor(int armor_amount){
    for (int i = 0; i < armor_amount; i++) {
        armor[i] = 1;
    }
}

int Party::getTreasurePrice() {
    int value = 0;
    for (int i = 0; i < 5; i++) {
        switch(treasures[i]) {
        case 'R':
            value += 10;
        break;

        case 'N':
            value += 20;
        break;

        case 'B':
            value += 30;
        break;

        case 'C':
            value += 40;
        break;

        case 'G':
            value += 50;
        break;
        }
    }
    return value;
}