#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
    private:

        string player_name;
        int fullness;
        bool armor;
        char weapon_type;

    public:

        Player(string player_name);

        string getPlayerName();
        void setPlayerName(string input_name);

        int getFullness();
        void setFullness(int input_fullness);

        char getWeaponType();
        void setWeaponType(char weapon_type);

        bool getArmor();
        void setArmor(bool input_armor);

};

#endif