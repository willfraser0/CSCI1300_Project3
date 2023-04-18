#### **CSCI 1300 CS1: Starting Computing: Project 3 Dungeon Escape**
#### **Godley/Hoefer - Spring 2023**
#### **Due: April 30<sup>th</sup> by 11:59 PM MST**

# DUNGEON ESCAPE 

For the Final Project you will implement a text-based adventure game in C++. 
The game takes inspiration from the tabletop roleplaying game "**Dungeons and Dragons**." 
In the original game, each session differs from the next, depending on the story made up by the dungeon master and the way the players react to that story. 
But most commonly, the game consists of a party of players making their way through a dungeon by fighting monsters, solving puzzles, and interacting with characters.

![](img/dragon.png)

Our game will use this general blueprint as inspiration. 
An evil Sorcerer has captured a group of players and trapped them in a monster-filled, labyrinthine dungeon for their own amusement. 
The goal of this game is to make it out of the dungeon with as many party members alive as possible. 
Each turn in the dungeon makes you hungrier (reduces fullness) and has risks such as monsters and traps. You can fight monsters, speak to NPCs, and explore, but you must make it through the dungeon before the Sorcerer runs out of patience and destroys the dungeon, along with the player and all the party members!

## Table of Contents
**[Game Description](#game-description)**

**[Starting the Game](#starting-the-game)**
> [Visit the Merchant](#visit-the-merchant)
>> [Merchant Menu](#merchant-menu)
>> - [Ingredients](#1-ingredients)
>> - [Weapons](#2-weapons)
>> - [Armor](#3-armor)
>> - [Cookware](#4-cookware)
>> - [Selling Treasures](#5-selling-treasures)

[Escaping the Dungeon](#escaping-the-dungeon)
> [Status Update](#status-update)
>
> [Map](#map)
> - [Generation](#generation)
> - [Space Types and "Explore"-ing](#space-types-and-explore-ing)
> - [Using the Map](#using-the-map)
>
> [Action Menu](#action-menu)
>> [Normal Space Actions](#normal-space-actions)
>> 1. [Move](#1-move)
>> 2. [Investigate](#2-investigate)
>> 3. [Pick a Fight](#3-pick-a-fight)
>> 4. [Cook and Eat](#4-cook-and-eat)
>> 5. [Give up](#5-give-up)
>>
>> [NPC Space Actions](#npc-space-actions)
>> 1. [Move](#1-move-1)
>> 2. [Speak to NPC](#2-speak-to-npc)
>> 3. [Give up](#3-give-up-1)
>>
>> [Room Space Actions](#room-space-actions)
>> 1. [Move](#1-move-2)
>> 2. [Open the Door](#2-open-the-door)
>> 3. [Give up](#3-give-up-2)
>
> [Main Menu](#main-menu)
>
> [Misfortunes](#misfortunes)
> 
> [Fighting a Monster](#fighting-a-monster)
> 1. [Attack](#1-attack)
> 2. [Surrender](#2-surrender)
> 
> [Sorcerer's Anger](#sorcerers-anger)
> 
> [Completing Puzzles](#completing-puzzles)
> 1. [NPC Puzzle](#1-npc-puzzle)
> 2. [Door puzzle](#2-door-puzzle)
>
> [Death by Hunger](#death-by-hunger) 
>
> [Monsters Text File](#monsters-text-file)

[Game End](#game-end)

[Collaboration](#collaboration)

[Requirements](#requirements)

> [Minimum Requirements](#minimum-requirements)
> 
> [Group Requirements](#group-requirements)
>
> [Extra Credit](#extra-credit)

[Interview Grading](#interview-grading)

[Timeline:](#timeline)


[Collaboration:](#collaboration)
> 
> **[Project 3 Points:](#project-3-points)**

# Game Description

The game can be summarized by these core concepts: 

1.  The player [buys supplies from merchants](#merchant-menu) before starting the journey through the dungeon.
2. There are five locked rooms in the dungeon, each of which must be [cleared](#2-open-the-door) (i.e., the monsters inside must be defeated). After clearing all five rooms, the exit of the dungeon will unlock.
3. There are two ways to find keys to unlock rooms: [fighting monsters](#fighting-a-monster) and [investigating spaces](#2-investigate).
4. There are opportunities to [cook food from raw ingredients](#4-cook-and-eat) along the way. 
5. There are chances to find [additional merchants](#2-speak-to-npc) along the way.
6. The player must manage fullness levels of the party to avoid dying by hunger.
7. The player can find various treasures around the map which can be sold to merchants.
8. Misfortunes frequently occur.
9. Every time the player moves to a space which is not marked as [explored](#space-types-and-explore-ing), the [Sorcerer's anger](#sorcerers-anger) level rises by 1. Once the Sorcerer is defeated in the final room, the Sorcerer's anger level no longer increases.
10. The [game ends](#game-end) when the player (and at least one of the companions) clear all the rooms and reach the end of the dungeon, when the player loses all their party members, or when the Sorcerer anger level reaches 100.

# Starting the Game
Each run through of the game should be a little different. As such, the [dungeon map](#map) will be randomized at the beginning of the game. See [Map Generation](#generation) for more details.

At the beginning of the game, the player (the leader of the party) is asked to enter their name,
followed by the names of their other four traveling companions 
Each party member starts with 50 fullness points. If any party member's fullness level drops to zero, they will perish from starvation at the end of the next turn. Different events will cause fullness to drop (see [Misfortunes](#misfortunes)). You can [cook and eat meals](#4-cook-and-eat) to restore fullness, **up to a maximum of 50**.

The [Sorcerer](#sorcerers-anger) starts with an anger level of 0. The game ends when the level reaches 100.

The party starts with 100 gold pieces.
The game begins with an opportunity to spend that gold in order to buy items from the merchant (see [Merchant Menu](#merchant-menu)).

After leaving the merchant, you should place the party in the upper left corner of the Map, then display the [Main Menu](#main-menu), including the [Current Status](#status-update), the [Map](#map), and the relevant [Action Menu](#action-menu) for the space the party is on.
The player must clear all five rooms and navigate to the dungeon exit with at least one additional party member surviving.

## Visit the Merchant

At the beginning of the game, the player has the opportunity to purchase things they might need on their long journey. 
Initially, the player is presented with the information about what they might need from the merchant and why. 
Below is an example excerpt for the game.

```
Between the 5 of you, you have 100 gold pieces. 
You will need to spend the some of your money on the following items:

- INGREDIENTS. To make food, you have to cook raw ingredients.
- COOKWARE. If you want to cook, you have to have cookware first.
- WEAPONS. You'll want at least one weapon per party member to fend off monsters.
- ARMOR. Armor increases the chances of surviving a monster attack.

You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price...
```
Then, display the [Merchant Menu](#merchant-menu).
### Merchant Menu
Players will have the opportunity to purchase items from and sell treasures to merchants, 
both at the beginning of the game, as well as when they encounter NPCs and solve their riddles (see [Speak to NPC](#2-speak-to-npc)).

The prices listed below **only** apply to the merchant at the beginning of the game. 
For other merchants encountered during their adventure, the price of items will increase based on the number of rooms cleared.
For each room cleared, the prices increase by 25% of the original prices, rounded down to the nearest integer. 
For example, after clearing the first room, the prices will be **25% higher**. 
After the second room, they will be **50% higher**, after the third room, **75% higher**, and so on. 

An example is given below, but you must display the following:
 1. The current inventory (gold, ingredients, cookware, weapons, armor, and treasures).
 2. The five options listed below.

Present the player with the information about possible purchases.
After the player makes a selection ask them what specific item they would like to buy if applicable (cookware and weapons), then ask them how many they would like to purchase, then finally print their total and ask them to confirm their purchase.

An example interaction with a merchant is given in [merchant_menu.txt](text_files/merchant_menu.txt) as well as shown below.
In this example, all instances of `>` denote that the following value was entered by the player.
The formatting in the following is a suggestion, feel free to be creative! 
```
If you're looking to get supplies, you've come to the right place.
I would be happy to part with some of my wares...for the proper price!

+-------------+
| INVENTORY   |
+-------------+
| Gold        | 100
| Ingredients | 0 kg
| Cookware    | P: 0 | F: 0 | C: 0
| Weapons     | C: 0 | S: 0 | R: 0 | B: 0 | L: 0
| Armor       | 0
| Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0
 
Choose one of the following:
 1. Ingredients: To make food, you have to cook raw ingredients.
 2. Cookware: You will need something to cook those ingredients.
 3. Weapons: It's dangerous to go alone, take this!
 4. Armor: If you want to survive monster attacks, you will need some armor.
 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.
 6. Leave: Make sure you get everything you need, I'm leaving after this sale!

> 2

I have a several types of cookware, which one would you like?
Each type has a different probability of breaking when used, marked with (XX%).

Choose one of the following:
 1. (25%) Ceramic Pot [2 Gold]
 2. (10%) Frying Pan [10 Gold]
 3. ( 2%) Cauldron [20 Gold]
 4. Cancel

> 3

How many would you like? (Enter a positive integer, or 0 to cancel)

> 1

You want to buy 1 Cauldron(s) for 20 Gold? (y/n)

> y

Thank you for your patronage! What else can I get for you?

+-------------+
| INVENTORY   |
+-------------+
| Gold        | 80
| Ingredients | 0 kg
| Cookware    | P: 0 | F: 0 | C: 1
| Weapons     | C: 0 | S: 0 | R: 0 | B: 0 | L: 0
| Armor       | 0
| Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0
 
Choose one of the following:
 1. Ingredients: To make food, you have to cook raw ingredients.
 2. Cookware: You will need something to cook those ingredients.
 3. Weapons: It's dangerous to go alone, take this!
 4. Armor: If you want to survive monster attacks, you will need some armor.
 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.
 6. Leave: Make sure you get everything you need, I'm leaving after this sale!

> 1

How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)

> 30

You want to buy 30 kg of ingredients for 30 Gold? (y/n)

> y

Thank you for your patronage! What else can I get for you?

+-------------+
| INVENTORY   |
+-------------+
| Gold        | 50
| Ingredients | 30 kg
| Cookware    | P: 0 | F: 0 | C: 1
| Weapons     | C: 0 | S: 0 | R: 0 | B: 0 | L: 0
| Armor       | 0
| Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0
 
Choose one of the following:
 1. Ingredients: To make food, you have to cook raw ingredients.
 2. Cookware: You will need something to cook those ingredients.
 3. Weapons: It's dangerous to go alone, take this!
 4. Armor: If you want to survive monster attacks, you will need some armor.
 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.
 6. Leave: Make sure you get everything you need, I'm leaving after this sale!

> 3

I have a plentiful collection of weapons to choose from, what would you like?
Note that some of them provide you a special bonus in combat, marked by a (+X).

Choose one of the following:
 1. Stone Club [2 Gold]
 2. Iron Spear [2 Gold]
 3. (+1) Mythril Rapier [5 Gold]
 4. (+2) Flaming Battle-Axe [15 Gold]
 5. (+3) Vorpal Longsword [50 Gold]
 6. Cancel

> 3

How many would you like? (Enter a positive integer, or 0 to cancel)

> 2

You want to buy 2 (+1) Mythril Rapier(s) for 10 Gold? (y/n)

> y

Thank you for your patronage! What else can I get for you?

+-------------+
| INVENTORY   |
+-------------+
| Gold        | 40
| Ingredients | 30 kg
| Cookware    | P: 0 | F: 0 | C: 1
| Weapons     | C: 0 | S: 0 | R: 2 | B: 0 | L: 0
| Armor       | 0
| Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0
  
Choose one of the following:
 1. Ingredients: To make food, you have to cook raw ingredients.
 2. Cookware: You will need something to cook those ingredients.
 3. Weapons: It's dangerous to go alone, take this!
 4. Armor: If you want to survive monster attacks, you will need some armor.
 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.
 6. Leave: Make sure you get everything you need, I'm leaving after this sale!

> 4

How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)

> 5

You want to buy 5 suit(s) of armor for 25 Gold? (y/n)

> y

Thank you for your patronage! What else can I get for you?

+-------------+
| INVENTORY   |
+-------------+
| Gold        | 15
| Ingredients | 30 kg
| Cookware    | P: 0 | F: 0 | C: 1
| Weapons     | C: 0 | S: 0 | R: 2 | B: 0 | L: 0
| Armor       | 5
| Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0

Choose one of the following:
 1. Ingredients: To make food, you have to cook raw ingredients.
 2. Cookware: You will need something to cook those ingredients.
 3. Weapons: It's dangerous to go alone, take this!
 4. Armor: If you want to survive monster attacks, you will need some armor.
 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.
 6. Leave: Make sure you get everything you need, I'm leaving after this sale!

> 6

Are you sure you're finished? You won't be able to buy anything else from me! (y/n)

> y

Stay safe out there! Goodbye!
```
**Some key notes**
 1. At any time in the buying process, if the player is attempting to buy an item 
  (or a number of items of the same kind) whose price exceeds the total gold the player has in hand, 
  print a message to the player informing them they do not have enough money and ask them to 
  choose another quantity of the item in question. 

 2. The player's inventory and gold should be updated after each purchase and displayed again along with
  the merchant menu.

 3. The player can buy from each category (ingredients, cookware, weapons, armor) multiple times, 
  so long as they still have the required money. 

 4. You may change the dialog and menu format as you see fit! 
  For example, if you want to allow the player to select multiple items within the same category before
  finalizing the sale, you may do so. You could even implement some kind of shopping cart!
  Be creative, but make sure that all of the below options are fully functional.

More detail on each category and item is given below for your reference. 
Feel free to provide as much (or as little) of this information as you would like to the player, but all of the described functionality must be implemented in your game.
#### 1. Ingredients

1. The merchant recommends the player(s) should purchase at least 10 kg of ingredients per person, at 1 gold piece per kilogram of food.
2. Ask the player how many kilograms of ingredients they wish to purchase.
3. Compute and print the current total cost so far.

#### 2. Weapons

1. You need weapons to be able to fend off monsters, otherwise, you can only run! Equipping your team with the maximum number of weapons (1 weapon per person) and buying upgraded weapons that are worth 5 gold pieces will maximize your chances of survival during an attack. You can have a maximum of 5 weapons. These are the different types of weapons:
    - A club (C) costs 2 gold pieces.
    - A spear (S) costs 2 gold pieces.
    - A +1 rapier (R) costs 5 gold pieces.
    - A +2 battle-axe (B) costs 15 gold pieces.
    - A +3 longsword (L) costs 50 gold pieces.
2. Ask the player which weapons they would like to purchase.
3. Compute and print the current total cost so far. 

#### 3. Armor

1. A set of armor costs 5 gold pieces. Armor protects you from monsters. Equipping your team with the maximum amount of armor (1 armor per person) will maximize your chances of survival during an attack. Adding more armor on top of the maximum amount will not increase your chances further.
2. Ask the player how many sets of armor they would like to purchase.
3. Compute and print the current total cost so far. 

#### 4. Cookware

1. A ceramic pot (P) costs 5 gold pieces. You can use a ceramic pot to stew and boil ingredients. It is made from weaker material, so it has a **25% chance** of breaking each time you use it.
2. A frying pan (F) costs 10 gold pieces. You can use a frying pan to sizzle ingredients. It is not as sturdy as a cauldron, with a **10% chance** of breaking each time you use it.
3. A cauldron (C) costs 20 gold pieces. You can use a cauldron to stew and boil ingredients. It is made of thick sturdy metal, so it only has a **2% chance** of breaking each time you use it.
4. Ask the player which cookware they would like to buy. They can buy different types, and more than one.
5. Compute and print the current total cost so far. 

#### 5. Selling Treasures

During your journey, you may encounter pieces of treasure in each room. 
When you encounter friendly merchants on the map, you can sell them pieces of treasure. 
The price of each treasure depends upon the number of rooms cleared when it was found. 
Once you sell a piece of treasure, it is removed from your inventory and cannot be purchased back from the
merchant.

  - 1 Room: Silver ring (R) - 10 gold pieces each
  - 2 Rooms: Ruby necklace (N) - 20 gold pieces each
  - 3 Rooms: Emerald bracelet (B) - 30 gold pieces each
  - 4 Rooms: Diamond circlet (C) - 40 gold pieces each
  - 5 Rooms: Gem-encrusted goblet (G) - 50 gold pieces each

# Escaping the dungeon

The goal of the game is to successfully navigate to all five rooms, clear them, and navigate to the exit. 
To enter each room, you must find a key. 
Keys can be dropped by a monster or found by investigating spaces on the map.   

## Status Update

Each turn, your program needs to display a **Status Update**. 
Here are the categories you need to display:

  - Number of rooms cleared
  - Number of keys found
  - Fullness levels of each member of the party
  - Ingredients available (in kg) 
  - Cookware available
  - Weapons and armor available
  - Gold pieces available
  - Treasure items available
  - Sorcerer's anger level

The following is an example of a status update, but you can modify its
appearance as you see fit
```
+-------------+
| STATUS      |
+-------------+
| Rooms Cleared: 1 | Keys: 0 | Anger Level: 12
+-------------+
| INVENTORY   |
+-------------+
| Gold        | 32
| Ingredients | 15 kg
| Cookware    | P: 1 | F: 1 | C: 1
| Weapons     | C: 1 | S: 2 | R: 1 | B: 0 | L: 1
| Armor       | 4
| Treasures   | R: 1 | N: 0 | B: 0 | C: 0 | G: 0
+-------------+
| PARTY       |
+-------------+
| Zach | Fullness: 40
| Morgan | Fullness: 40
| Christopher | Fullness: 45
| Enora | Fullness: 41
| Jot | Fullness: 43
+-------------+
```
## Map

We've provided a fully implemented Map class that you will need to figure out how to use in your code. 
The Map class defines a 2D map of size 12x12 and stores data in a member 2D character array called `map_data_`.
This array contains characters that represent the player, room, and NPCs, as well as empty spaces. 

Setters and getters are provided for the player's position. 
Add functions are provided for rooms (`Map::addRoom`) and NPCs (`Map::addNPC`) which place these entities in `map_data_`.
Similarly, there are remove functions which remove a room or NPC and mark the space as "explored", see `Map::removeRoom` and `Map::removeNPC`.
You will use these remove functions after the player clears a room or interacts with an NPC, respectively.

In the `mapData`, `'X'` corresponds to the party's position, `'N'` is an NPC location, and `'R'` is a room location. 
Normal spaces are represented by `'-'` and explored spaces are represented by a space `' '`. 
NPC locations are not shown on the map (that is, they appear as `'-'`) until after they are encountered.

Functions for displaying the map in the terminal and moving the player around the map are also given.

Use [Map.h](map/Map.h) as a reference for the member functions of `Map`.

You may modify this class in any manner you see fit &mdash; by changing the types of entities, the size of the map (the map must be **at least** 12x12), etc. 
But, you must use a 2D map as part of your project.

### Generation

The file [mapDriver.cpp](map/mapDriver.cpp) shows an example of how you may use the class. It first initializes a `Map` object, then and adds entities relevant to this game (NPC, player, rooms).
The NPCs will not show on the map until they are encountered, the rest will have their respective symbols of `X` and `R`.

In your project, each run through the dungeon should feel a little different.
As such, **the 5 rooms and 5 NPCs should be randomly placed throughout the map at the start of the game**.

You can use the example code used initialize the map, given in [`mapDriver.cpp`](map/mapDriver.cpp), as a starting point, but you should create your own function which places the 5 rooms and 5 NPCs randomly throughout the map.

### Space Types and "Explore"-ing"
There are 4 types of spaces on the map.
1. Normal spaces: These are the most common type of space and are marked with a `'-'`. See [Normal Space Actions](#normal-space-actions) for more details on what the player can do on normal spaces. If the player chooses to take the [Investigate action](#2-investigate), then the space will be marked as "explored" by changing its character to a space `' '`.
2. Room spaces: These spaces are marked with an `'R'` and represent rooms on the map. See [Room Space Actions](#room-space-actions) for more details. After the room has been "cleared", that is, the party has entered the room and defeated the monster inside, the space will be turned into a normal space and marked as "explored" by changing its character to a space `' '`.
3. NPC spaces: These spaces are marked with an `'N'` and represent non-player characters that the party can interact with. See [NPC Space Actions](#npc-space-actions) for more details. These spaces are hidden by default, so they will be displayed on the map as a `'-'` until the player moves onto their space. Moving off of the NPC space will leave it revealed as a `'N'`. The player can choose to interact with the NPC. After the player interacts with the NPC, the NPC will leave. This means the space will be changed to a normal space and marked as "explored" by changing its character to a space `' '`.
4. Dungeon exit: The final, and least interesting, space type is the dungeon exit, marked with a `'E'`. After clearing all the rooms, the party will have to move to this space to finish the game.

Note, each space type (excluding the dungeon exit) has a specific action that the player can perform which will result in the space being marked as "explored" by changing its character to a space `' '`.
Simply moving over spaces **WILL NOT** mark the room as "explored". 
### Using the Map
After displaying the status, you should display the map, with updated information. See [Main Menu](#main-menu) for an example in context.

The `Map` class provides some member functions which provide some functionality you will need for your project.

First, the `Map::move` function takes a single parameter, `char direction`, which determines which way the party will move.
Direction should be one of `w` (up), `a` (left), `s` (down), or `d` (right). 

Additionally, the `Map::removeRoom(int row, int col)` and `Map::removeNPC(int row, int col)` functions will be useful for updating the map after a room is cleared or the party interacts with an NPC, respectively.

See the following block for an example of navigating the map, removing rooms/NPCs, and marking a space as "explored". 
The code used to generate these maps is given in [mapDriver.cpp](map/mapDriver.cpp).
```
X-----------
------------
---R---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Let's move a little. First, down:
```
------------
X-----------
---R---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Now, right:
```
------------
-X----------
---R---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Moving onto an NPC space that was previously hidden:
```
------------
--X---------
---R---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Let's move off it, should be updated as visible:
```
------------
--NX--------
---R---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Okay, let's move onto the room:
```
------------
--N---------
---X---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
... and move left off
```
------------
--N---------
--XR---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Let's remove that room
```
------------
--N---------
--X ---R----
------------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
Let's investigate the current space and thus mark it as "explored". Then, move down to see the space.
```
------------
--N---------
--  ---R----
--X---------
------------
-------R----
------------
------------
--R--------R
------------
------------
------E-----
```
## Action Menu

After displaying the status and map, you should allow the player to choose from the following **Actions**.

The player chooses one among the set of allowed actions in a space (see below for details). 
After the chosen action, **excluding the Move action**, is completed, there is a **40% chance** of a random misfortune
(see section below on how to handle misfortunes).

The actions which are valid depend on the type of the current space.

### Normal Space Actions

If the space is normal (non-NPC, non-room), then prompt the player to choose one of the following:

#### 1. Move   
The party moves a single space in any of the cardinal directions.
After moving, each party members' fullness level has a **20% chance** of dropping by 1.
This random event should be computed independently for each of the party members.

#### 2. Investigate

If the space is not currently marked as "explored" on the map, the player can choose to investigate their surroundings in hopes of finding a key or treasure.
If the space is already marked as "explored", inform the player that the space cannot be investigated again and prompt them to
select a different option.
If this option is selected, then the space is marked as "explored" and the following occurs:

1. (**10% chance**) that the player finds the key!
2. (**20% chance**) that the player finds a piece of treasure (which treasure is determined by the number of cleared rooms).
3. (**20% chance**) that the player has to fight a random monster. See the section on "Fighting a Monster" to learn about battle gameplay mechanics, including rewards for winning and punishments for losing. If the monster is defeated, there is a **10% chance** that the monster will drop a key.
4. After investigating the space (no matter the outcome), every party member's fullness level has a **50% chance** to drop by one point. If the player fought a monster, they do not have this chance applied twice.

#### 3. Pick a Fight   

Picking a fight will cause a random monster to appear.
See the section on "Fighting a Monster" to learn about battle gameplay mechanics, including rewards for winning and consequences for losing.
If the monster is defeated, there is a **10% chance** that the monster will drop a key.
After any monster battle, no matter the outcome, every party member's fullness level has a **50% chance** to drop by one point.

#### 4. Cook and Eat

If you have ingredients, you can choose to cook the ingredients into a meal.
When cooking, prompt the player to select which cookware item they want to use, as well as how many kg of ingredients they want to cook **in increments of 5 kg**.
There is a **5:1 ratio between kg of ingredients, and amount of fullness increased by a successfully cooked meal**. 

See [Cookware](#4-cookware) above to learn the chance of a successful cook. 
- **If the cookware breaks** while trying to cook, then **the meal is not created**, **the ingredients are lost**, and **the cookware is removed from the player inventory**. 
  A message should be shown to the player to let them know their cook failed.
- If the cook is successful, display a message to the user telling them so.

After either a successful or unsuccessful cook, display the fullness levels of each party member, as well as the remaining number of kg of food.

**Note:** The people in your party share meals, and the fullness level will increase by the same amount for each person. For example, if you cook a meal with 5 kg of food, then each person's fullness will increase by 1. 


#### 5. Give up

If the player chooses to give up, the game ends. Print a message expressing regret the adventurers could not make it out of the dungeon.

### NPC Space Actions

If the space contains a non-player character (NPC), **reveal the space** as such on the map **as soon as the player moves into the space for the first time**. 
In NPC spaces, the actions of the party are considerably more limited.

Prompt the player to choose from the following:

#### 1. Move
The party moves a single space in any of the cardinal directions.
After moving, each party members' fullness level has a **20% chance** of dropping by 1.
This random event should be computed independently for each of the party members.

#### 2. Speak to NPC

When the player speaks to the NPC (non-player character), they must solve a puzzle. 
See [Completing Puzzles](#completing-puzzles) to learn how the riddle puzzle gameplay mechanics' work.

1. If the player successfully completes the puzzle, the NPC will be friendly to the party and willing to sell items to the player. 
  The NPC will ask the user if they wish to barter for goods. If they say yes, open the [Merchant Menu](#visit-the-merchant) with prices adjusted according to the number of cleared rooms.
  The prices should increase according to the number of cleared rooms as mentioned previously. 

2. Otherwise, the NPC will become hostile to the player. In this case, the NPC will summon a random monster that must be fought. The good news is that this monster may drop the key, with the same likelihood as shown in "Fighting a Monster."

3. Regardless of the outcome, the NPC will leave after speaking with the player. That is, **the space will change from an NPC space to a normal space which is marked as "explored"**.

#### 3. Give up

If the player chooses to give up, the game ends. Print a message expressing regret the adventurers could not make it out of the dungeon. Additionally, print the final statistics as explained in [Game End](#game-end).

### Room Space Actions

If the space is marked as a room, then the player should choose between one of the following options:

#### 1. Move   
The party moves a single space in any of the cardinal directions.
After moving, each party members' fullness level has a **20% chance** of dropping by 1.
This random event should be computed independently for each of the party members.

#### 2. Open the Door
If the player has a key, then they can enter the room and must immediately fight a monster.
This monster is chosen from the list for challenge ratings **two levels higher** than the current number of cleared rooms. 
That is, the first room will have a monster with challenge rating 2, the second room will have a monster with challenge rating 3, etc. 
In the 5th and final room, the players will fight the only challenge rating 6 enemy: the Sorcerer!
1. If the party successfully defeats the monster, then there is a **60% chance** of a misfortune occurring. After resolving the misfortune, the room space is changed to a normal space on the map and the number of rooms cleared increases by one.
2. If the party fails to defeat the monster, then the consequences described in [Fighting a Monster](#fighting-a-monster) occur, the key is lost, and the player must use another key to reopen the room. Moreover, there is a **40% chance** of a misfortune occurring.

If the player does not have any keys, but tries to open the door to a room anyway, they fall into a trap, and must solve a puzzle to get out of the trap. See [Completing Puzzles](#completing-puzzles) to learn how this gameplay mechanic works.

#### 3. Give up

If the player chooses to give up, the game ends. Print a message expressing regret the adventurers could not make it out of the dungeon. Additionally, print the final statistics as explained in [Game End](#game-end).

## Main Menu
Each turn, you will display a status update, followed by the map, followed by the correct action menu based on the current party location. 
For example:
```
+-------------+
| STATUS      |
+-------------+
| Rooms Cleared: 1 | Keys: 0 | Anger Level: 12
+-------------+
| INVENTORY   |
+-------------+
| Gold        | 32
| Ingredients | 15 kg
| Cookware    | P: 1 | F: 1 | C: 1
| Weapons     | C: 1 | S: 2 | R: 1 | B: 0 | L: 1
| Armor       | 4
| Treasures   | R: 1 | N: 0 | B: 0 | C: 0 | G: 0
+-------------+
| PARTY       |
+-------------+
| Zach | Fullness: 40
| Morgan | Fullness: 40
| Christopher | Fullness: 45
| Enora | Fullness: 41
| Jot | Fullness: 43
+-------------+

  ------------
  --N---------
  -- ---R-----
  --X---------
  ------------
  -------R----
  ------------
  ------------
  --R--------R
  ------------
  ------------
  ------E-----
  Select one:
  1. Move
  2. Investigate
  3. Pick a Fight
  4. Cook and Eat
  5. Give up

> 
```

## Misfortunes

There is more to the game than fighting monsters and moving through spaces. 
Each turn in the game, after the player chooses and completes one action (except for moving), there is a **40% probability** a misfortunate event might occur. 

If a misfortune occurs at the end of a particular turn, choose one misfortune at random from the following options. We provide probabilities, but feel free to change the probabilities or even add additional misfortunes.

1. **(30% Chance)** Your team is robbed! Lose ingredients (10 kg), cookware (1 item), or armor (1 item) chosen randomly. Print a message announcing the misfortune: 

> OH NO! Your team was robbed by dungeon bandits!  
>
> You lost 1 Cauldron!

2. **(10% Chance)** One of the weapons/armor, chosen at random, breaks. Print a message announcing the misfortune: 

> OH NO! Your +1 Rapier broke! 

3. **(30% Chance)** Food poisoning: One party member got food poisoning, causing them to lose 10 points of hunger. If this causes them to reach zero fullness, they [die of hunger](#death-by-hunger) immediately. 

4. **(30% Chance) Team member locked in the previous room** - **This misfortune can only happen if a player tries to open the door with the key. If this misfortune is chosen after any other action, nothing happens.** One party member at random (**never the party leader**) gets chosen to be locked behind in the previous room. Announce the misfortune as follows: 

> OH NO! Your teammate Jot is trapped in the previous room and is unable to get through. You must continue without them.
> 
> Your party size has reduced to 4 members. 

If the team size is not enough to complete the journey (at least one person besides the team leader), the game ends (see [Game End](#game-end))

**Note:** If you want to implement "positive events" you are free to include those as well. 
For example: "The family discovered a lost pirate
treasure chest. Your gold reserves increase by 100 gold pieces".

## Fighting a Monster

No two excursions through the dungeon are exactly the same. 
Players come into contact with different monsters based on how many rooms of the dungeon have been cleared. 
The monsters are grouped by their **challenge rating**. 
The challenge rating of encountered monsters starts at 1, and increases by one for each room cleared.

A sample table of monsters is found in the file [monsters.txt](text_files/monsters.txt).
See the [Monsters Text File](#monsters-text-file) section for specific details.
You can, and should, add additional monsters with challenge ratings from 1-5, but there should only be one challenge rating 6 monster (the Sorcerer).

When a player encounters a monster, there will be an equal probability of which monster the party will fight. 
For example, prior to clearing the first room, the party has an **equal chance** of either fighting Animated Armor, Bugbear, Harpy, or Scarecrow.
After clearing the first room, the party has an **equal chance** of either fighting a Minotaur, Owlbear, Banshee, or Wereboar.

Once a monster is defeated, it **will no longer appear**.
That is, if the party defeats the Animated Armor, the next time they encounter a monster, they will only have a chance of encountering the Bugbear, Harpy, or Scarecrow.

When a player begins a fight with a monster, print a message announcing the event and print out the name of the monster encountered:

> MINOTAUR AHEAD! THEY LOOK HOSTILE!

If the party has at least one weapon, they are given the option to fight or surrender.
Otherwise, they only have the option to surrender.

### 1. Attack: 
The party can attempt to fight the monster. 
The success of the battle depends on an equation with different variables depending on the party's weapons and armor. 
If the party has purchased any upgraded weapons that are worth 5 gold pieces or more (+1 rapier, +2 battle-axe, or +3 longsword), then add bonus points for each upgraded weapon according to their bonus to the party weapon strength, $w$, variable. 

For example, if a party has 2 clubs, 1 spear, 1 rapier, and 1 battle-axe, then the party weapon strength, $w$, is:

$$
  w = 5 \text{(num weapons)} + 1 \text{(+1 rapier)} + 2 \text{(+2 battle-axe)} = 8
$$

**Note: Each party member can only hold one weapon**, so if a party member has died, their weapon cannot contribute to the party weapon strength.

Calculate the following variables:
  - $w$ = \# of weapons the party possesses + the bonus point(s) for each upgraded weapon (e.g. add +2 if the party is using a +2 battle-axe). 
  - $d$ = 4 if each party member has a different type of weapon; 0 if not
  - $a$ = \# of sets of armor the party possesses
  - $c$ = the challenge rating of the monster
  - $r_1$ = random number from 1 to 6
  - $r_2$ = random number from 1 to 6 (independent of $r_1$)

Using these variables, use this formula to determine the outcome of the battle :

$$
\left(r_1 * w + d\right) - \frac{r_2 * c}{a}
$$

If the result of the formula is greater than 0, the party wins
the battle. 
If the result is less than or equal to 0, the party loses.

If they win the battle, the traveling party gains $(10\cdot c)$ gold pieces and $(5\cdot c)$ kg of ingredients from the monster, where $c$ is the challenge rating of the monster. In addition, there is a **10% chance** the monster will drop a key.
Finally, once a monster is defeated, it will **never appear again**. Make sure to keep track of what monsters the party has defeated!

If they lose the battle, the party loses a quarter of their gold reserves (rounded down to the nearest integer), up to 30 kg of ingredients, and each party member, excluding the player, independently has an **10% chance** of being slain by a monster, but if they are wearing armor, then they only have a **5% chance** of being slain. 
If any party member is slain in the process, the party loses that member. 
You should print a message announcing this party member's death.

**Note:** The party can only choose to attack if they have at least one weapon.

### 2. Surrender: 
 One member, never the player, from the traveling party was unable to escape the wrath of the monster and is held captive. 
 The traveling party surrenders their fight with the monster and must continue on their journey and leaves this member behind. 
 The party loses one member.

After any monster battle, no matter the outcome, every party member's fullness level has a **50% chance** to drop by one point.

## Sorcerer's Anger

The Sorcerer will get increasingly angry at the party as they proceed through the dungeon. 
Specifically, **each time the party moves to a space which is not marked as "explored"** (including to uncleared Room spaces and NPC spaces), **the Sorcerer's anger will increase by one**.

If the anger ever reaches 100, the Sorcerer will destroy the entire dungeon with the party still trapped inside, causing the player to lose.

Additionally, the party will fight the Sorcerer in the final room of the dungeon (as they are the only monster with challenge rating 6). 
This fight will use the same formula as was used for fighting other monsters (see [Fighting a Monster](#fighting-a-monster)) unless you choose to implement a special boss fight for this battle for extra credit (see [Extra Credit](#extra-credit)).

Once the Sorcerer is defeated, that is, the 5th room is cleared:
1. The Sorcerer's anger will no longer increase.
2. No additional monster encounters will occur.

## Completing Puzzles

The player has to complete a puzzle in order to interact with NPCs or after attempting to open a door without a key.

### 1. NPC Puzzle

When you encounter an NPC, in order to persuade them to sell you their wares, you must first solve a riddle. 
The riddle the NPC tells you can be chosen from a list of riddles from an external text file, [riddles.txt](text_files/riddles.txt), where each line has a riddle and the riddle's answer separated by a comma. 

### 2. Door puzzle

When you attempt to open a door without having found the key, the party is trapped in a door puzzle. 
The puzzle requires the player to play a game of Boulder/Parchment/Shears against the door. 
The player is allowed to pick one of Boulder/Parchment/Shears as their choice, and the door randomly picks one of the three as well (You can assign a number to each of the three choices and randomly generate a number as the choice for the door).
The player wins/solves the puzzle if their choice beats the door's choice, based on the rules below:

  - Boulder beats Shears
  - Parchment beats Boulder
  - Shears beat Parchment

If the player's choice matches the door's choice (it's a tie), then the player will be forced into another round of Boulder/Parchment/Shears until the player's choice beats the door's choice. 

If the player wins, however, **the party can enter the room without using a key**.

If the player is unable to beat the door in three attempts, then they lose one party member at random (the player is never chosen).

**Note:** feel free to come up with other puzzles for the player to
solve. Consider the puzzles above an example. You can ask the player to
solve anagrams, a system of equations... it's your choice. Make it fun!

## Death by Hunger
If the player or a party member's fullness level reaches zero, then at the end of the next turn, they will die of hunger. 
You may want to print a warning about the party members' impending demise at the beginning of the next turn:
```
Warning: Morgan is on the brink of starvation!
You should cook and eat some food!
```
You should announce death by hunger like so:
```
OH NO! Morgan has died of hunger!
Your party size has reduced to 4 members.
```
If the party leader, i.e. the player, dies from hunger, then they lose immediately and the game ends. See [Game End](#game-end) for details on ending the game.
## Monsters Text File

The monsters are written in a file [monsters.txt](text_files/monsters.txt). Each line lists the
monster's name, followed by the challenge rating of that monster,
separated by a comma. Here is the content of the file:
```
Animated Armor,1
Bugbear,1
Harpy,1
Scarecrow,1
Minotaur,2
Owlbear,2
Banshee,2
Wereboar,2
Giant Crocodile,3
Troll,3
Hobgoblin Warlord,3
Mammoth,3
Stone Giant,4
Night Hag,4
Assassin,4
Hydra,4
Cloud Giant,5
Silver Dragon,5
Vampire,5
Lich,5
Sorcerer,6
```
You may add additional monsters with challenge ratings 1-5, but there must always be exactly one challenge rating 6 monster, the Sorcerer. 

# Game End

The player wins the game when:
- The party clears all five rooms and the player and at least one other party member proceeds to the dungeon exit.

The player loses the game when: 
- All party members other than the player die.
- The Sorcerer's anger level becomes 100, and they takes their wrath out on the player by destroying the entire party!

Remember the player and their companions can die from hunger, a monster
attack, or the Sorcerer reaching an anger level of 100. In addition,
party members can be surrendered to monsters or lost in the dungeon
forever. You should make checks each turn to verify these conditions to
see if the player has lost the game before each action the user takes.

If the game ends, your program should print a message informing either
of the tragic event that caused the loss or congratulating the player on
their success. Either way, you should also print the following
statistics:
- Name of the leader and any remaining party members
- Number of rooms cleared
- Gold pieces remaining
- Treasure items in the party's inventory
- Number of spaces "explored" (including spaces which used to have an NPC or a room)
- Number of monsters defeated
- Number of turns elapsed

**You should also save the final stats of the game in a file named**
*results.txt*. 
You can choose the format of this file.

# Collaboration
The collaboration policy outlined in the syllabus applies to this project. As such, **all work for this assignment must be original work**. Every project (group or single) must be original and not similar to ANY other source (internet, paid tutor, fellow student, projects from previous years, etc). You may collaborate and brainstorm with other people, but each assignment submission is to be the unique creation of the author(s). Your code must be original and unique. 

Your work may not include code taken from online resources (e.g. Chegg, StackExchange, etc.) or from other students (past or present), even with modification. Any such instances constitute Academic Dishonesty (passing off others' work as your own) and will earn you a 0 on the assignment and a trip to the Honor Code Council. If a group project is found to be non-unique and deemed worthy of being sent to Honor Code Council then BOTH parties are guilty (even if one party decides to “take the blame”). 

Outside resources (e.g. C++ documentation, StackOverflow, etc.) that are referenced when writing your own solution should be cited explicitly (in code comments, for example). Referencing these types of resources (to, for example, find a specific piece of C++ syntax or understand what an error message means) when writing code is expected; it is not acceptable to use *solutions* (i.e. C++ implementations of algorithms) from any external source, even if they are cited.

**Choose your groups wisely! If you aren’t sure if something is okay, then please ask!**
# Requirements
The minimum requirements for this final project are in the following sections. You are **not allowed** to use `stringstream` objects, pointers, or global variables.

## Minimum Requirements

Your implementation of Dungeon Escape should have: 
  - 4+ user defined classes 
      - At least two classes with 4+ data members. 
      - At least one class must include an array of objects from a class that you created.
      - Appropriate methods for each class (including getters, setters, default constructors, and parametrized constructors as needed) 
  - Your project implementation must include at least: 
      - 6+ if-else statements 
      - 6+ loops (while loops, for loops, do-while, in total) 
      - 2+ nested loops 
      - File IO (both reading from a file and writing to a file) 
  - Your project must have an interactive component (ask the user for input, create a menu for choices, ...). 
  - Game stats should be displayed as instructed (see [Status Update](#status-update)) at each turn. It's more exciting and meaningful! Also, these stats help debug the code. 

## Group Requirements
In addition to the requirements listed above, if you work in a group you must also implement a sorting algorithm and apply it to a task in your program. You should not use a Library function or any external (to this course) resources to implement the sorting algorithm.

One situation where the sorting functionality would be useful is for a ranking task, for example: ranking the number of turns it took each player to reach the final boss.

**Note**: 
- If you work in a team and you do not implement a sorting task, 50 points will be deducted from your point total.
- We expect that you will be contributing to the project equally. **Both group members must submit a zip file for the project**, and the solution files can be the same. Indicate your partner’s name in comments at the top of each code file. Both partners will book an Interview Grading appointment together and TAs will be grading you individually. 


## Extra Credit
Following are some extra credit opportunities available for this project. 
  1. **Final boss battle with the Sorcerer (10 Points)** 
    In the base game, the fight with the Sorcerer is treated just like any other monster. 
    For extra credit, make this fight feel more like a final
    battle: you could change the formula to make it more difficult,
    have multiple phases of the fight, have a special puzzle that the
    player must solve in order to outwit the Sorcerer, or something
    else of your own design. Be creative!

  2. **Persistent Scoreboard (10 Points)** Make a scoreboard to rank players' attempts to get through the dungeon. 
    You will need to:
      1. Define what factors will determine a player's score. Create
        your own formula, maybe using the number of rooms cleared,
        number of turns, gold and treasure collected, number of
        monsters defeated, and even the amount of time it took the
        player to complete the game.
    
      2. Keep track of the player name and score in a text file, for
         example *scoreboard.txt*, which you will update after each
         playthrough.
      
      3. In addition to printing out the final statistics at the end of
         the game, show the player where they are on the current
         scoreboard.

3. **Resurrection (5 Points)** Introduce some mechanic to resurrect fallen party members. 
  Be creative, and be sure to make the mechanic sufficiently difficult
  or expensive in order to maintain game balance.

4. **Present your project (10 points)** during lecture or through a video. 
   * **Lecture**: A sign-up sheet will be shared a week before class presentations
   * **Video**: Make a 5-minute (+ or - 1 min) video explaining: 
      * The project idea 
      * Implementation and approach 
      * A demonstration of the working project 

# Interview Grading

The Project 3 interview grading scheduler will be available on Canvas before the deadline of this project. The
interviews will take place between **May 1<sup>st</sup>** and **May 4<sup>th</sup>**. If you don’t sign-up to meet between **May 1<sup>st</sup>** and **May 4<sup>th</sup>** or you miss your interview, then no points will be awarded for the project. If you work in a group, **both group members should attend the same interview grading slot.**

During the interview grading, TAs will be playing your game and asking conceptual questions. They will also ask about your functionality and implementation.

# Timeline 

- **April 10<sup>th</sup> – 12<sup>th</sup>: Project design meetings (optional).** Meet with professors/TAs to discuss your project ideas and the classes you will create and use. You should bring your class files and code (a list of classes and methods you will implement) to the meeting. During the meeting, we will go over your classes to see if they’re feasible and meet requirements. 
    - Prior to Monday, April 10<sup>th</sup>, you must have reserved a slot on the Project 3 Design Meeting Scheduler and have the meeting date reserved for a day on or before Wednesday April 12<sup>th</sup>. 
    - If your project idea gets rejected you have till April 13 <sup>th</sup> to make the suggested changes and submit the class files and skeleton.

- **Thursday, April 13<sup>th</sup>, 11:59 pm: Submit class files & Code Skeleton.**
  Your `.h` files should be complete with all the data
  members and member functions you will be using for each class. For the
  class implementation `.cpp` files, you should fully implement simple
  functions like your getters and setters. For more complex functions you
  can include function stubs with detailed comments. 

  For example, if we were stubbing a function to implement bubble sort and
  return the number of swaps we might give in our code skeleton: 
  ```c++
  /* 
    1. Compare adjacent elements. If the first is greater than the second,
    swap them. 
    2. Do this for each pair of adjacent elements, starting with the first
    two and ending with the last two. At this point the last element should
    be the greatest. 
    3. Repeat the steps for all elements except the last one. 4. Repeat
    again from the beginning for one less element each time, until there are
    no more pairs to compare. 
  */ 
  int bubble_sort(int arr[], int size) 
  { 
    int swaps = 5; 
    return swaps; // function returns expected type (int) 
  }
  ```

- **Wednesday, April 26<sup>th</sup>, 11:59 pm: Interview Grading Sign-Up deadline**.
  You must sign up for an interview grading timeslot
  no later than **Wednesday, April 26<sup>th</sup> at 11:59 pm**. The
  interviews will take place between **May 1<sup>st</sup>** and
  **May 4<sup>th</sup>**. If you don't sign-up or you miss your
  interview, then **no points will be awarded for the project**. 

  During the interview grading, TAs will be playing your game and asking
  questions about your game. They will also ask about your implementations
  and conceptual questions. 

- **Thursday, April 27<sup>th</sup>, 11:59 pm: Final Deliverables**.
  Your project will be due on **Sunday, April 27<sup>th</sup>, 11:59 pm**.
  You must submit a zip file to **Project 3** assignment on Canvas,
  including all `.h` and `.cpp` files. The submission should compile and run.
  TAs will also be grading comments and style. 

- **Friday, April 28<sup>th</sup>, 11:59 pm: Project Report**. 
  Write a 1-2 page report containing the following reflection questions: 

    - How did you prepare for the project? 
    - How did you develop our code skeleton? In what way(s) did you use your code skeleton? 
    - Reflect on how you could have done better or how you could have completed the project faster or more efficiently? 
    - In addition, write a paragraph answering the following question, in the context of the Project in CSCI 1300: Did you have any false starts, or begin down a path only to have to turn back when figuring out the strategy/algorithm for your Final Project program? Describe in detail what happened, for example, what specific decision led you to the false starts, or, if not, why do you think your work had progressed so smoothly. In either case, give a specific example. 

  The report should be a **1-inch margin, single space, 12pt font size,
  Times New Roman**. Submit a report as PDF to **Project3 Report** on Canvas. 
  **Every team member should submit an individual report, clearly distinct in content from their teammate.**


## Collaboration

All work for this assignment (and of course in general) must be original
work. Every project (group or single) must be original and not similar
to ANY other source (internet, paid tutor, fellow student, past years
projects, etc). You may collaborate and brainstorm with other people,
but each assignment submission is to be the unique creation of the
author(s). Your code must be original and unique. Your work may not
include code taken from online resources like Chegg or StackExchange, or
from other students (past or present), even with modification. Any such
instances constitute Academic Dishonesty (passing off others' work as
your own) and will earn you a 0 on the assignment and a trip to the
Honor Code Council. If a group project is found to be non-unique and
deemed worthy of being sent to Honor Code Council then BOTH parties are
guilty (even if one party decides to "take the blame"). Choose your
groups wisely! If you aren't sure if something is okay, then please
ask! 

## Project 3 Points

Project 3 is worth 150 points. Here is a summary of the points. 

| **Criteria**                                                      | Points |
| ----------------------------------------------------------------- | ------ |
| Code Skeleton                                                     | 10     |
| Project Report                                                    | 10     |
| Minimum Implementation Requirements                               | 30     |
| Game functionality                                                | 50     |
| Game Compilation, Algorithm, Comments, Style, Interview Questions | 50     |
| Recitation attendance (Weeks 13, 15, 16)*                         | -30    |
| Total                                                             | 150    |

**Note**: if your code does not compile, you cannot score above 50
points for the project.
