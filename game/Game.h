//
//  Game.h
//  pa3
//
//  Created by Aly Shehata on 4/23/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef pa3_Game_h
#define pa3_Game_h
#include "curses.h"
#include <vector>
#include "DungeonLevel.h"
#include "Player.h"
#include "Factory.h"
using namespace::std;
class Game{

public:
    Game();
    void initialState();
    void drawLevel();
    void playGame();
    void insertPlayer();
    void moveUnit(string direction, Unit* myUnit);
    bool takeTurn();
    void displayInventory();
    void moveCreatures();
    void goUp();
    void goDown();
    void generateUnits();
    void moveUnits();
    void generateItems();
    void attack(Unit* myUnit);
    Item* checkItems();
    void pickup();
private:
    
    vector<DungeonLevel> myLevels;
    vector<vector<char>> currentLevelChars;
    vector<vector<Weapon*>> myGameWeapons;
    vector<vector<Unit*>> myGameUnits;
    vector<vector<Item*>> myGameItems;
    int dlvl;
    Player myPlayer;
    int myMoves;
    mt19937 mt;
    string currentArmor;
    int currentProtection;
    string currentWeapon;
    int currentDamage;
};




#endif
