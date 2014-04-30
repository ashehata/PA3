//
//  Consumable.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Consumable.h"
#include "Item.h"
Consumable::Consumable()
{
    myNutrition = 0;
    myHealth = 0;
    
}


int Consumable::getHealth()
{
    return myHealth;
}
void Consumable::setHealth(int health)
{
    myHealth = health;
    
}
int Consumable::getNutrition()
{
    return myNutrition;
}
void Consumable::setNutrition(int nutrition)
{
    myNutrition = nutrition;
}

void Consumable::use(Unit &user)
{
    
}







