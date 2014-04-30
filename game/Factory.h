//
//  Factory.h
//  pa3
//
//  Created by Aly Shehata on 4/25/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef pa3_Factory_h
#define pa3_Factory_h
#include "XMLSerializable.h"
#include "XMLParser.h"
#include "Unit.h"
#include "Weapon.h"
#include "Item.h"
#include "Armor.h"
#include <random>


class Factory{
public:
    
    static Factory & Instance();
    virtual ~Factory();
    virtual Unit* generateUnit(int maxLevel);
    virtual Item* generateItem();
    virtual Weapon* generateWeapon();
    //virtual Armor* generateArmor();
    
    
private:
    Factory();
    vector<Unit*> myUnits;
    vector<Item*> myItems;
    vector<Weapon*> myWeapons;
    mt19937 rand;
    
};




#endif
