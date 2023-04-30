#include <iostream>
#include <stdlib.h>
#include "Monster.h"
#include "Party.h"
#include "Player.h"

Monster::Monster()
{
monster_name = "";
challenge_rating = "";
}

Monster::Monster(string i_monster_name, int i_challenge_rating)
{
monster_name = i_monster_name;
challenge_rating = i_challenge_rating;
}



string Monster::getMonsterName()
{
    return monster_name;
}

string Monster::setMonsterName(string input_name)
{
    monster_name = input_name;
}

int Monster::getMonsterRating()
{
    return challenge_rating;
}

int Monster::setMonsterRating(int input_rating)
{
    challenge_rating = input_rating;
}

void Monster::KillMonster(int monster_id)
{
    monster_list.erase(monster_id);
}

void Monster::populateMonsters()
{
    ifstream file_input;
    file_input.open(Monsters.txt);

    string line = "";
    string arr_monsters[2];
    int monster_id = 0;

    while (getline(file_input, line)) //reads until the end of the file
    {

        if (line.empty())
        {
            continue; // Ignore empty lines
        }
        else
        {
            splitMonster(line, ',', arr_monsters, 2);
            monster_name = arr_monsters[0];
            challenge_rating = stoi(arr_monsters[1]);

            monster_list[monster_id] = Monster(monster_name, challenge_rating);
        }

        if (monster_id < 21)
        {
            monster_id++;
        }
        else
        {
            break;
        }
    }
}

void Monster::fightDialogue()
{
    cout << "You've encountered a(n) " << << "." << endl;

    if (Party.getWeaponStrength() == 0)
    {
        Monster.surrenderDialogue();
    }
}

void Monster::surrenderDialogue()
{

    cout << "Oh no! You've surrendered!" << party_members.back().getPlayerName() << " has perished. Each of your remaining players has a 50% chance to lose one fullness." << endl;

    for (int member_id = 0; i < Party.getAmountPartyMembers(); i++)
    {
        srand(time(0));
        int r = rand();
        if (r % 2 != 0) //50 percent chance of odd or even number, if not even, remove 1 health from player
        {
            int new_fullness = Party.getFullness() - 1;
            Party.setFullness(member_id, new_fullness);
        }
    }

    Party.displayInventory();
}

int Monster::setRoomsCleared()
{
    int rooms_cleared = Party.getRoomsCleared();
}

int Monster::getWeaponStrength()
{
    return Party.getWeaponStrength();
}

int getWeaponDifference()
{


}

int getAmountArmor()
{
    int amount_armor=0;

}



int Monster::getRandomNumber(int lower_limit, int upper_limit)
{

    int num = -100;

    while (num < lower_limit || num > upper_limit)
    {
        num = rand();
    }

    return num;
}

int Monster::splitMonster(string input_string, char separator, string arr[], int arr_size)
{
    //declare variables
    int k = 0;
    int delim_i = 0;
    int num_splits = 0;

    for (int i = 0; i < input_string.length(); i++) //loop to iterate over entire length of input string
    {
        if (input_string.length() == 0) //if empty string, end program
        {
            return 0;
        }

        if (input_string[i] == separator) //if separator found
        {
            num_splits++;                     //add 1 to split counter
            string str = "";                  //create empty string
            for (int j = delim_i; j < i; j++) //loop to iterate starting from the index of the last separator and ending at the deliminator found
            {
                str = str + input_string[j]; //create new string from everything before found deliminator
            }

            arr[k] = str;    //set new string into position of array dependent on how many splits have already ocurred
            delim_i = i + 1; //reset the deliminator index
            k++;             //set position of array to next
        }

        if (i == (input_string.length() - 1) && k >= 1) //if reached end of input string and there have been splits
        {
            string str = "";                   //create empty string
            for (int j = delim_i; j <= i; j++) //loop to iterate between position of last deliminator and index at end of string
            {
                str = str + input_string[j]; // assign last remaining string to new string
            }
            arr[k] = str; //set new string into position of array dependent on how many splits have already ocurred
            num_splits++; //add one to split counter
        }

        if (i == (input_string.length() - 1) && num_splits == 0) //if reached the end of input string, and no splits, create new string from input string
        {
            num_splits = 1;  //set num splits to 1 for return value
            string str = ""; //create new empty string
            for (int j = 0; j <= i; j++)
            {
                str = str + input_string[j]; //put entirity of input string into new string
            }
            arr[0] = str; //set new string as first position of array
        }
    }
    if (num_splits > arr_size) //if more splits than size of the array, return -1
    {
        return -1;
    }
    else
    {
        return num_splits; //return num splits
    }
}
