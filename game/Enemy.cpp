//
//  Enemy.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Enemy.h"


Enemy::Enemy()
{
    
    hostile = false;

}
bool Enemy::isHostile()
{
    return hostile;
    
}
void Enemy::setHostile(bool value)
{
    hostile = value;
}
void Enemy::takeTurn()
{
    //To be continued...
}


void Enemy::dumpObject()
{
    cout << "Enemy:" << endl;
    dumpObjectData();
}
void Enemy::dumpObjectData()
{
    Unit::dumpObjectData();
    string hostile = "false";
    if (isHostile())
        hostile = "true";
    cout << "       Hostile: " << hostile << endl;
}

void Enemy::writeFragment(std::ostream & output)
{
    output << "  <Enemy>" << endl;
    writeDataAsFragment(output);
    output << "  </Enemy>" << endl;
    
}
void Enemy::writeDataAsFragment(std::ostream & output)
{
    string hostile = "false";
    Unit::writeDataAsFragment(output);
    if (isHostile())
        hostile = "true";
    output << "      <hostile>" << hostile << "</hostile>" << endl;
    
}

void Enemy::setElementData(string myElementName, string myValue)
{
    
    Unit::setElementData(myElementName, myValue);
	if( myElementName == "hostile" ){
		if (myValue == "true")
            setHostile(true);
        else
            setHostile(false);
    }
}