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
        int weapons[5] = {0};
        bool armor[5] = {0};
        int fullness[5] = {50};
        vector<Player> party_members;

    public:

        Party();
        void addMember(string member_name);
        void removeMember(int member_id);
        Player Member(int member_id);
        int getAmountPartyMembers();

        int getPlayerFullness(int member_id);
        void setPlayerFullness(int member_id, int fullness);
    
        string getLastMemberName();

        void removeLastMember();

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

        void addCookware(char input_cookware);
     
        void addTreasure(char input_treasure);
        int getTreasurePrice();

        void getWeapons();
        void addWeapons(char weapon_type, int amount);

        int getArmor();
        void addArmor(int armor_amount);
    
        int getWeaponStrength();
    
        int getWeaponDifference();
    
        


};

#endif
