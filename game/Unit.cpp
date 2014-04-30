//
//  Unit.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Unit.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
Unit::Unit()
{
    myLevel = 0;
    myHealth = 0;

    
}

int Unit::getLevel()
{
    return myLevel;
    
    
}
void Unit::setLevel(int level)
{
    myLevel = level;
    
}
int Unit::getHealth()
{
    return myHealth;
    
}
void Unit::setHealth(int health)
{
    myHealth = health;
    
    
}
void Unit::attack(Unit target)
{
    
    //To be continued
    
}



void Unit::dumpObjectData()
{
    Entity::dumpObjectData();
    cout << "       Health: " << getHealth() ;
    cout << "   Level: "<< getLevel() <<endl;
}


void Unit::writeDataAsFragment(std::ostream & output)
{
    Entity::writeDataAsFragment(output);
    output << "      <health>" << getHealth() << "</health>" << endl;
    output << "      <level>" << getLevel() << "</level>" << endl;
    
}
void Unit::setElementData(string myElementName, string myValue)
{
    
    Entity::setElementData(myElementName, myValue);
	if( myElementName == "health" ){
		setHealth(atoi(myValue.c_str()));
	}
	else if( myElementName == "level" ){
		setLevel(atoi(myValue.c_str()));
	}
    
}


void Unit::setWeapon(Weapon* newWeapon){
    myWeapon = newWeapon;
}

void Unit::setArmor(Armor* newArmor){
    myArmor = newArmor;
}

Armor* Unit::getArmor(){
    return myArmor;
}

Weapon* Unit::getWeapon(){
    return myWeapon;
}


void Unit::setDisplayChar(char myChar){
    displayChar = myChar;
}

char Unit::getDisplayChar()
{
    return displayChar;
}

void Unit::addItem(Item *myItem)
{

        Weapon* w_Weapon2 = dynamic_cast<Weapon*>(myItem);
        Armor* a_Armor2 = dynamic_cast<Armor*>(myItem);
        
        if(w_Weapon2 != NULL)
        {
            setWeapon(w_Weapon2);
        }
        if(a_Armor2 != NULL)
        {
            setArmor(a_Armor2);
        }
        
        myItems.push_back(myItem);
    

}
void Unit::setYX(int y, int x){
    myX = y;
    myY = x;
    
}

int Unit::getX(){
    
    return myX;
}

int Unit::getY(){
    
    return myY;
}
