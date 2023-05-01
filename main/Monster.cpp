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

int Monster::battleCalculation()
{
    int battle_result=0;
    int random1=Monster.getRandomNumber(1, 6);
    int random2=Monster.getRandomNumber(1, 6);
    int armor=Monster.getAmountArmor();
    int weapon=Monster.getWeaponStrength();
    int weapon_difference=Monster.getWeaponDifference();
    int challenge_rating=Monster.getFirstMonsterRating();

    battle_result=(random1 * weapon + weapon_difference)-((random2*challenge_rating)/(armor))

    return battle_result;

}

string Monster::getMonsterName()
{
    return monster_name;
}

int Monster::getMonsterRating()
{
    return challenge_rating;
}


string Monster::getFirstMonsterName()
{
    return monster_list[0].getMonsterName();
}

int Monster::getFirstMonsterRating()
{
    return stoi(monster_list[0].getMonsterRating());
}


void Monster::setMonsterName(string input_name)
{
    monster_name = input_name;
}

int Monster::setMonsterRating(int input_rating)
{
    challenge_rating = input_rating;
}

void Monster::killFirstMonster()
{
    monster_list.erase(monster_list.begin());
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
            monster_name = arr_monsters[0];           //take name from split
            challenge_rating = stoi(arr_monsters[1]); //take challenge rating from split

            monster_list[monster_id] = Monster(monster_name, challenge_rating);//place monster in monstsers vector
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

Monster Monster::spawnMonster()
{
    string name = monster_list[0].getMonsterName();
    int challenge = monster_list[0].getMonsterRating();

    Monster spawned_monster = Monster(name, challenge);

}


void Monster::fightDialogue()
{
    cout << "You've encountered a(n) " << Monster.getFirstMonsterName() << "with a challenge rating of "<< Monster.getFirstMonsterRating() << endl;

    if (Party.getWeaponStrength() == 0)
    {
        Monster.surrenderDialogue();
    }
    string response="";
    cout << "Would you like to fight or surrender? (f/s)" << endl;
    cin >> response;

    if(response==s)
    {
        Monster.surrenderDialogue();
    }
    else if(response==f)
    {
        cout << "You chose to fight! The winner will be decided based on a calculation involving total weapon strength, weapon difference, amount of armor, the monsters challenge rating, and some chance." << endl;

        int result = Monster.battleCalculation();

        if(result <= 0)
        {
            cout << "Your party has lost the battle. You have lose 20 gold pieces and 20 ingredients." << endl;

            if(Monster.getRandomNumber(0, 10)==1)
            {
                cout << "A member of your party has perished from the battle. Rest in peace, " << Party.getLastMemberName() << endl;
                Party.removeLastMember();
            }

        }
        else if(result>0)
        {
            cout << "Congratulations, you and your party have won the battle! You will recieve some gold and ingredients scaled to the monsters challenge rating. The monster is dead and will not be encountered again." << endl;
            Party.addGold(10 * Monster.getFirstMonsterRating());
            Party.addIngredients(5 * Monster.getFirstMonsterRating());
            Monster.killFirstMonster();
            Party.displayInventory();
        }

    }
}

void Monster::surrenderDialogue()
{

    cout << "Oh no! You've surrendered!" << Party.getLastMemberName() << " has perished. Each of your remaining players has a 50% chance to lose one fullness." << endl;

    Party.removeLastMember();
    
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

int Monster::setRoomsCleared(int rooms_cleared)
{
    int rooms_cleared = Party.getRoomsCleared();
}

int Monster::getWeaponStrength()
{
    return Party.getWeaponStrength();
}

int Monster::getWeaponDifference()
{
    return Party.getAmountDifferentWeapons();
}

int Monster::getAmountArmor()
{
    return Party.getArmor();
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
