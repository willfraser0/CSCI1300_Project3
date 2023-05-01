#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include <string>
#include "Player.h"

using namespace std;

class Party {
    private:

        int rooms_cleared;
        int gold_coins;
        int ingredients;

        int cookware[3]; // {ceramic pot (P), cauldron (C), }frying pan (F),
        int treasures[5]; // {Silver ring (R), Ruby necklace (N), Emerald bracelet (B), Diamond circlet (C), Gem-encrusted goblet (G)}
        char weapons[5] = {0};
        bool armor[5] = {0};
        vector<Player> party_members;

    public:

        Party();
        void addMember(string member_name);
        void removeMember(int member_id);
        Player Member(int member_id);
    
        string getLastMemberName();

        void addRoomCleared();
        int getRoomsCleared();

        void setGold(int input_gold);
        void addGold(int input_gold);
        int getGold();

        void setIngredients(int input_Ingredients);
        void addIngredients(int input_Ingredients);
        int getIngredients();

        void displayInventory();
        void cook();

        void addCookware(char input_cookware, int amount);
        void addTreasure(char input_treasure);
        int getTreasurePrice();

        void getWeapons();
        void addWeapons(char weapon_type, int amount);

        void getArmor();
        void addArmor(int armor_amount);

        void getWeaponStrength();
    
        int getWeaponDifference();
        void sellTreasure();

        void merchantDialogue();
};

#endif
