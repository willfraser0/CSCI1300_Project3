#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include <string>
#include "Player.h"

using namespace std;

class Party {
    private:

        int gold_coins;
        int ingredients;

        int cookware[3]; // {ceramic pot (P), cauldron (C), frying pan (F)}
        int treasures[5]; // {Silver ring (R), Ruby necklace (N), Emerald bracelet (B), Diamond circlet (C), Gem-encrusted goblet (G)}

        vector<Player> party_members;

    public:

        Party();
        void addMember(string member_name);
        void removeMember(int member_id);
        Player Member(int member_id);

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

        //

};

#endif