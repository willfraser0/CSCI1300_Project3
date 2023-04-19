#include <string>
using namespace std;
#include "Player.h"

Player::Player(string input_name) {
    player_name = input_name;
    fullness = 50;
    armor = false;
    weapon_type = ' ';
}

string Player::getPlayerName(){
    return player_name;
}

void Player::setPlayerName(string input_name){
    player_name = input_name;
}

int Player::getFullness(){
    return fullness;
}

void Player::setFullness(int input_fullness){
    fullness = input_fullness;
}

char Player::getWeaponType(){
    return weapon_type;
}

void Player::setWeaponType(char input_weapon){
    string vaild_weapons= "CSRBL";
    weapon_type = input_weapon;
}

bool Player::getArmor() {
    return armor;
}

void Player::setArmor(bool input_armor) {
    armor = input_armor;
}