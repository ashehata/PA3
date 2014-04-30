//
//  Unit.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Unit__
#define __pa1_1__Unit__

#include <iostream>
#include "Entity.h"

class Item;
class Tile;
class Weapon;
class Armor;

class Unit: public Entity
{
public:
    Unit();
    virtual int getLevel();
    virtual void setLevel(int level);
    virtual int getHealth();
    virtual void setHealth(int health);
    virtual void attack(Unit target);
	virtual void dumpObjectData();
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);
    virtual void setDisplayChar(char displayChar);
    virtual char getDisplayChar();
    virtual void addItem(Item* myItem);
    virtual void setWeapon(Weapon* newWeapon);
    virtual Weapon* getWeapon();
    virtual void setArmor(Armor* newArmor);
    virtual Armor* getArmor();
    virtual void setYX(int y, int x);
    virtual int getX();
    virtual int getY();

private:
    char displayChar;
    int myLevel;
    int myHealth;
    Weapon* myWeapon;
    Armor* myArmor;
    vector<Item*> myItems;
    int myX;
    int myY;
    
};

#endif /* defined(__pa1_1__Unit__) */
