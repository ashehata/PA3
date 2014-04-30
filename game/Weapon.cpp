//
//  Weapon.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Weapon.h"
#include "Item.h"

Weapon::Weapon()
{
    myDamage = 0;
    myType = "Unknown Weapon";
}

int Weapon::getDamage()
{
    return myDamage;
}
void Weapon::setDamage(int damage)
{
    myDamage = damage;
    
}
string Weapon::getType()
{
    return myType;
}
void Weapon::setType(string type)
{
    myType = type;
    
}




void Weapon::dumpObject()
{
    cout << "Weapon:" << endl;
    dumpObjectData();
}
void Weapon::dumpObjectData()
{
    Item::dumpObjectData();
    cout << "       Damage: " << getDamage() ;
    cout << "   Type: "<< getType() <<endl;
}

void Weapon::writeFragment(std::ostream & output)
{
    output << "  <Weapon>" << endl;
    writeDataAsFragment(output);
    output << "  </Weapon>" << endl;
    
}
void Weapon::writeDataAsFragment(std::ostream & output)
{
    Item::writeDataAsFragment(output);
    output << "      <damage>" << getDamage() << "</damage>" << endl;
    output << "      <type>" << getType() << "</type>" << endl;
    
}
void Weapon::setElementData(string myElementName, string myValue)
{
    
    Item::setElementData(myElementName, myValue);
	if( myElementName == "type" ){
		setType(myValue);
	}
	else if( myElementName == "damage" ){
		setDamage(atoi(myValue.c_str()));
	}
    
}


void Weapon::setYX(int y, int x){
    myX = y;
    myY = x;
    
}

int Weapon::getX(){
    
    return myX;
}

int Weapon::getY(){
    
    return myY;
}


