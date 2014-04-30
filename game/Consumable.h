//
//  Consumable.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Consumable__
#define __pa1_1__Consumable__

#include <iostream>
#include "Item.h"

class Consumable: public Item
{
    
public:
    Consumable();
    int getHealth();
    void setHealth(int health);
    int getNutrition();
    void setNutrition(int nutrition);
    virtual void use(Unit & user);

    
    
private:
    int myHealth;
    int myNutrition;
};



#endif /* defined(__pa1_1__Consumable__) */
