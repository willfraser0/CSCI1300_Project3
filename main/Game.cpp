#include <string>
#include <cassert>
#include "Map.h"
#include "Party.h"
#include "Player.h"
//1
using namespace std;

void merchantDialogue(Party party, int rooms_cleared) {

    char input;
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl << endl;

    party.displayInventory();
    
    cout << "Choose one of the following:" << endl;
    cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
    cout << "2. Cookware: You will need something to cook those ingredients." << endl;
    cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
    cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
    cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
    cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl << endl;
    cin >> input;

    switch (input) {
        case '1':
        
        break;
        case '2':
        
        break;
        case '3':
        
        break;
        case '4':
        
        break;
        case '5':
        
        break;
        case '6':
        
        break;
        default:
            cout << "Please enter a valid choice" << endl;
        break;
    }
}

int main() {

    // create party and map
    Party party;
    Map map;
    int sorcer_anger = 0;
    int rooms_cleared = 0;

    // create party member 0 (you)
    string temp_name;
    cout << "Enter your name: ";
    cin >> temp_name;
    party.addMember(temp_name);

    // fill rest of party
    for (int i = 0; i < 4; i++) {
        cout << "Enter the name of party member " << i + 1 << ": ";
        cin >> temp_name;
        party.addMember(temp_name);
    }

    // merchant dialogue
    cout << endl << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items:" << endl << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl << endl;

    merchantDialogue(party, rooms_cleared);

    cout << "Initial map: " << endl;
    map.displayMap(); // starting point
    cout << "Room #: " << map.getRoomCount() << endl;

    // adding rooms
    assert(map.addRoom(2, 3));
    assert(map.addRoom(8, 11));
    assert(map.addRoom(2, 7));
    assert(map.addRoom(8, 2));
    assert(!map.addRoom(15, 15)); // should not show on map nor error out, out of bounds
    assert(!map.addRoom(2, 3));   // will not do anything since space is occupied
    assert(map.addRoom(5, 7));
    assert(!map.addRoom(3, 7)); // will fail due to exceeding max_rooms_
    map.displayMap();
    cout << "Spawning some NPCs: " << endl;
    assert(map.addNPC(4, 4));
    assert(map.addNPC(1, 2));
    assert(map.addNPC(7, 2));
    assert(map.addNPC(10, 4));
    assert(!map.addNPC(2, 7)); // should fail due to space being occupied
    assert(map.addNPC(9, 0));
    assert(!map.addNPC(10, 0)); // should fail due to max number of NPCs == 5
    map.displayMap();
    cout << "Let's move a little. First, down:" << endl;
    map.move('s'); // go down
    map.displayMap();

    return 0;
}
