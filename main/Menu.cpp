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
//1
#include "Map.h"
#include "Party.h"

using namespace std;

bool gameOver = false;

void handleInput(Map map, Party party);

int main() {

    Map map;
    Party party;

    

    map.addRoom(8, 8);
    map.addNPC(4, 4);

    // These functions let you detect keypresses without having to press enter 
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO,&old_tio);
    new_tio=old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    thread first(handleInput,map,party);

    while (!gameOver) {

         // this_thread::sleep_for(chrono::milliseconds(10));
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
                        map.enterRoom(map.getPlayerRow(), map.getPlayerCol(), monster_rng(rng)); // Fight monster
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