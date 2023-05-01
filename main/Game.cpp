#include <iostream>
#include <thread>
#include <random>
#include <future>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <tuple>
#include <vector>
#include <queue>

#include "Map.h"
#include "Party.h"

using namespace std;

int calculatePrice(int initial_price, int rooms_cleared)
{
    int new_price = initial_price + (initial_price * (.25 * rooms_cleared));
    return new_price;
}

void merchantDialogue(Party party, int rooms_cleared)
{

    int customer_input = 0;
    int customer_input_amount = 0;
    string customer_response = "";

    // if(something_purchased==false) we might need to check for something purchased to only display the welcome part once
    // {
    char input;
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl
         << endl;

    do
    {
        party.displayInventory();

        cout << "Choose one of the following:" << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl
             << endl;
        cin >> input;

        switch (input)
        { //second parameter of calculate price needs to be counter for amount of rooms cleared, to account for 25% price increase
        case '1':
            cout << "How many kg of ingredients do you need "
                 << "[" << calculatePrice(1, party.getRoomsCleared()) << " Gold/kg]?"
                 << "(Enter a positive mulitple of 5, or 0 to cancel)" << endl;
            cin >> customer_input;
            if (customer_input < 0 || customer_input % 5 != 0) //checks for negative input or a non multiple of 5
            {
                cout << "Invalid input" << endl;
                break;
            }
            cout << "You want to buy " << customer_input << " kg of ingredients for " << customer_input * calculatePrice(1, party.getRoomsCleared()) << " gold? (y/n)" << endl;
            cin >> customer_response;
            if (customer_response == "y" && party.getGold() >= (customer_input * calculatePrice(1, party.getRoomsCleared()))) //if customer has enough gold in inventory
            {
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                party.addIngredients(customer_input);
                party.setGold(party.getGold() - (customer_input * calculatePrice(1, party.getRoomsCleared()))); //remove gold spent
            }
            else if (customer_response == "n")
            {
                cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
            }
            else
            {
                cout << "Invalid input" << endl;
                break;
            }
            break;

        case '2':
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;

            cout << "Choose one of the following:" << endl;
            cout << "1. (25%) Ceramic Pot [" << calculatePrice(2, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "2. (10%) Frying Pan [" << calculatePrice(10, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "3. ( 2%) Cauldron [" << calculatePrice(20, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "4. Cancel" << endl;
            cin >> customer_input;

            if (customer_input > 0 && customer_input < 5)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> customer_input_amount;
            }
            else
            {
                cout << "Invalid input" << endl;
                break;
            }

            if (customer_input == 1)
            {
                cout << "You want to buy" << customer_input_amount << "Ceramic Pot(s) for " << customer_input_amount * calculatePrice(2, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                if (customer_response == "y" && party.getGold() >= (customer_input_amount * calculatePrice(2, party.getRoomsCleared())))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addCookware(0, customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(2, party.getRoomsCleared())));
                    break;
                }
                else if (customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
                else
                {
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            else if (customer_input == 2)
            {

                cout << "You want to buy " << customer_input_amount << " Frying Pan(s) for " << customer_input_amount * calculatePrice(10, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                if (customer_response == "y" && party.getGold() >= (customer_input_amount * calculatePrice(10, party.getRoomsCleared())))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addCookware(1, customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(10, party.getRoomsCleared())));
                    break;
                }
                else if (customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
                else
                {
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            else if (customer_input == 3)
            {

                cout << "You want to buy " << customer_input_amount << " Cauldron(s) for " << customer_input_amount * calculatePrice(20, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                if (customer_response == "y" && party.getGold() >= (customer_input_amount * calculatePrice(20, party.getRoomsCleared())))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addCookware(2, customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(20, party.getRoomsCleared())));
                }
                else if (customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                }
            }
            else if (customer_input == 4)
            {
                cout << "Do you still wish to buy ingredients? (y/n)" << endl;
                cin >> customer_response;
                if (customer_response == "y")
                {
                    break;
                }
                if (customer_response == "n")
                {
                    break;
                }
            }

            break;

        case '3':
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;

            cout << "Choose one of the following: " << endl;
            cout << "1. Stone Club [" << calculatePrice(2, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "2. Iron Spear [" << calculatePrice(2, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "3. (+1) Mythril Rapier [" << calculatePrice(5, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "4. (+2) Flaming Battle-Axe [" << calculatePrice(15, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "5. (+3) Vorpal Longsword [" << calculatePrice(50, party.getRoomsCleared()) << " Gold]" << endl;
            cout << "6. Cancel" << endl;
            cin >> customer_input;

            if (customer_input > 0 && customer_input < 6)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> customer_input_amount;
            }
            else if (customer_input != 6)
            {
                cout << "Invalid input" << endl;
                break;
            }
            else if (customer_input == 6)
            {
                cout << "Do you still want to buy any weapons? (y/n)" << endl;
                cin >> customer_response;
                if (customer_response == "y")
                {
                    cout << "Choose one of the following: " << endl;
                    cout << "1. Stone Club [" << calculatePrice(2, party.getRoomsCleared()) << " Gold]" << endl;
                    cout << "2. Iron Spear [" << calculatePrice(2, party.getRoomsCleared()) << " Gold]" << endl;
                    cout << "3. (+1) Mythril Rapier [" << calculatePrice(5, party.getRoomsCleared()) << " Gold]" << endl;
                    cout << "4. (+2) Flaming Battle-Axe [" << calculatePrice(15, party.getRoomsCleared()) << " Gold]" << endl;
                    cout << "5. (+3) Vorpal Longsword [" << calculatePrice(50, party.getRoomsCleared()) << " Gold]" << endl;
                    cout << "6. Cancel" << endl;
                    cin >> customer_input;
                }
                else if (customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }

            if (customer_input == 1)
            {
                cout << "You want to buy " << customer_input_amount << "Stone Club(s) for " << customer_input_amount * calculatePrice(2, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                if(customer_response == "y" && party.getGold() >= customer_input_amount * calculatePrice(2, party.getRoomsCleared()))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addWeapons('C',customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(2, party.getRoomsCleared())));
                }
                else if(customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }
            else if (customer_input == 2)
            {
                cout << "You want to buy " << customer_input_amount << "Iron Spear(s) for " << customer_input_amount * calculatePrice(2, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                if(customer_response == "y" && party.getGold() >= customer_input_amount * calculatePrice(2, party.getRoomsCleared()))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addWeapons('S',customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(2, party.getRoomsCleared())));
                }
                else if(customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }
            else if (customer_input == 3)
            {
                cout << "You want to buy " << customer_input_amount << "(+1) Mythril Rapier(s) for " << customer_input_amount * calculatePrice(5, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                 if(customer_response == "y" && party.getGold() >= customer_input_amount * calculatePrice(5, party.getRoomsCleared()))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addWeapons('R',customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(5, party.getRoomsCleared())));
                }
                else if(customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }
            else if (customer_input == 4)
            {
                cout << "You want to buy " << customer_input_amount << "(+2) Flaming Battle-Axe(s) for " << customer_input_amount * calculatePrice(15, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                 if(customer_response == "y" && party.getGold() >= customer_input_amount * calculatePrice(15, party.getRoomsCleared()))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addWeapons('B',customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(15, party.getRoomsCleared())));
                }
                else if(customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }
            else if (customer_input == 5)
            {
                cout << "You want to buy " << customer_input_amount << "(+3) Vorpal Longsword(s) for " << customer_input_amount * calculatePrice(50, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                 if(customer_response == "y" && party.getGold() >= customer_input_amount * calculatePrice(50, party.getRoomsCleared()))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addWeapons('L',customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(50, party.getRoomsCleared())));
                }
                else if(customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }

            break;

        case '4':
            cout << "The cost of one armor plate is " << calculatePrice(5, party.getRoomsCleared()) << " Gold. How many would you like to buy?" << endl;
            cin >> customer_input_amount;

            if (customer_input_amount > 0)
            {
                cout << "You want to buy " << customer_input_amount << " plate(s) of armor for " << customer_input_amount * calculatePrice(5, party.getRoomsCleared()) << " Gold? (y/n)" << endl;
                cin >> customer_response;
                 if(customer_response == "y" && party.getGold() >= customer_input_amount * calculatePrice(5, party.getRoomsCleared()))
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    party.addArmor(customer_input_amount);
                    party.setGold(party.getGold() - (customer_input_amount * calculatePrice(2, party.getRoomsCleared())));
                }
                else if(customer_response == "n")
                {
                    cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
                    break;
                }
            }
            break;

        case '5':
            party.displayInventory();

            cout << "I see you have collected some treasures. Would you like to sell them for " << party.getTreasurePrice() << " Gold? (y/n)" << endl;
            cin >> customer_response;

            if (customer_response == "y" && party.getTreasurePrice() !=0)
            {
                cout << "Pleasure doing business with you. Here is " << party.getTreasurePrice() << " Gold" << endl;
                party.addGold(party.getTreasurePrice());
                party.sellTreasure();
                party.displayInventory();
                
            }
            else if (customer_response == "n" || party.getTreasurePrice()==0)
            {
                cout << "I'm sorry, is there anything else you'd like to buy?" << endl;
            }
            break;
        case '6':
            cout << "Thanks for shopping. Good luck!" << endl;

        default:
            cout << "Please enter a valid choice" << endl;
            break;
        }
    } while (input != 6);
}


// Setup thread
void handleInput(Map map, Party party);

int main() {

    // Setup classes
    Map map;
    Party party;


    map.populateMap();

    // These functions let you detect keypresses without having to press enter 
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio=old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    thread first(handleInput,map,party);
    while (true) {

    }
    return 0;
}

void handleInput(Map map, Party party) { 

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> monster_rng(0,20);
    int monster;
    uniform_int_distribution<int> member_rng(1,4);
    int lost_member;

    int menu_level = 0;
    int current_monster;
    int monster_level;

    // Menu levels:
    // 0: base level
    // 1: fight
    // 2: cooking
    // 3: NPC

    while (true) {

        char c = getchar();

        if (menu_level == 0) {

            switch (c) {

                case 'w':
                    map.move('w');
                    map.displayMap();
                    break;

                case 'a':
                    map.move('a');
                    map.displayMap();
                    break;

                case 's':
                    map.move('s');
                    map.displayMap();
                    break;

                case 'd':
                    map.move('d');
                    map.displayMap();
                    break;

                case '0': // Exit
                    terminate();

                case '1': 

                    // Room option 1
                    if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())) { 
                        monster = monster_rng(rng);
                        monster_level = map.enterRoom(map.getPlayerRow(), map.getPlayerCol(), monster); // Fight monster
                        menu_level = 1;
                        break;
                    } 
                    // NPC option 1 
                    else if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())) {
                        map.speakToNPC(map.getPlayerRow(), map.getPlayerCol()); // Speak to NPC
                    } 
                    // Exit option 1
                    else if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())) {
                        map.escape(map.getPlayerRow(), map.getPlayerCol()); // Escape dungeon
                        terminate();
                    } 
                    // Normal option 1
                    else {
                        map.exploreSpace(map.getPlayerRow(), map.getPlayerCol()); // Explore space
                    }
                    
                    map.displayMap();
                    break;

                case '2':
                    
                    // Room option 2
                    if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())) { 
                        
                    } 
                    // NPC option 2 
                    else if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())) {
                        
                    } 
                    // Exit option 2
                    else if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())) {
                        
                    } 
                    // Normal option 2
                    else {
                        map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    }
                    
                    map.displayMap();
                    break;
                
            
                case '3':  // Cook and eat
                    if (map.isFreeSpace(map.getPlayerRow(), map.getPlayerCol())) {
                        party.cook();
                    } 
                    map.displayMap();
                    break;
            }
        } else if (menu_level == 1) {

            
            switch (c) {
                case '1':
                    cout << "You chose to attack" << endl;
                    break;

                case '2':
                    lost_member = member_rng(rng);
                    party.removeMember(lost_member);

                    cout << "You chose to surrender. Unfortunatly " << party.Member(lost_member).getPlayerName() << " died :(" << endl;
                    menu_level = 0;
                    map.displayMap();
                    break;
            }
        }
    }
}