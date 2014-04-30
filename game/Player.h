//
//  Player.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Player__
#define __pa1_1__Player__




#include <iostream>
#include "Unit.h"
#include "Item.h"

class Player: public Unit
{
public:
    Player();
    int getExperience();
    void setExperience(int experience);
    void setLevel(int level);
    int getLevel();
    void setHealth(int health);
    int getHealth();
    int getScore();
    void setScore(int score);
    string getName();
    void setDisplayChar();
    char getDisplayChar(char displayChar);
    void setYX(int y, int x);
    int getX();
    int getY();
    vector<Item*> getInventory();
    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);
    Armor* getArmor();
    void setArmor(Armor* armor);
    
private:
    string myName;
    int myExperience;
    int myHealth;
    int myScore;
    int myLevel;
    char myDisplay;
    int myX;
    int myY;
    Weapon* myWeapon;
    Armor* myArmor;
    
    
};

#endif /* defined(__pa1_1__Player__) */
