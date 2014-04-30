//
//  Armor.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Armor.h"

Armor::Armor()
{
    myProtection = 0;
    myType = "Unknown Armor";
}

int Armor::getProtection()
{
    return myProtection;
}
void Armor::setProtection(int protection)
{
    myProtection = protection;
}
string Armor::getType()
{
    return myType;
}
void Armor::setType(string type)
{
    myType = type;
}


void Armor::dumpObject()
{
    cout << "Armor:" << endl;
    dumpObjectData();
}
void Armor::dumpObjectData()
{
    Item::dumpObjectData();
    cout << "       Protection: " << getProtection() << endl;
    cout << "       Type: " << getType() << endl;

}

void Armor::writeFragment(std::ostream & output)
{
    output << "  <Armor>" << endl;
    writeDataAsFragment(output);
    output << "  </Armor>" << endl;
    
}
void Armor::writeDataAsFragment(std::ostream & output)
{
    Item::writeDataAsFragment(output);
    output << "      <protection>" << getProtection() << "</protection>" << endl;
    output << "      <type>" << getType() << "</type>" << endl;

}

void Armor::setElementData(string myElementName, string myValue)
{
    
    Item::setElementData(myElementName, myValue);
	if( myElementName == "type" )
        setType(myValue);
    if (myElementName == "protection")
        setProtection(atoi(myValue.c_str()));
}

void Armor::setYX(int y, int x){
    myX = y;
    myY = x;
    
}

int Armor::getX(){
    
    return myX;
}

int Armor::getY(){
    
    return myY;
}

