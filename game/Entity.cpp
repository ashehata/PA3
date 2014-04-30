//
//  Entity.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Entity.h"
#include "DungeonLevel.h"
Entity::Entity()
{
    myName = "";
    myDisplay = '?'; // blank space
    
}
string Entity::getName()
{

    return myName;
    
}

void Entity::dumpObject(){
	cout << "Entity:" << endl;
	dumpObjectData();
}

void Entity::dumpObjectData(){
	XMLSerializable::dumpObjectData();
    
	cout << "   Name: " << getName() << endl;
	cout << "   DisplayChar: " << getDisplayChar() << endl;
	cout << "   Properties: " << endl;
    
/*for( auto it = myProperties.begin(); it != myProperties.end();it++ ){
		cout << "       - " << (*it) << endl;
	}*/
}

void Entity::setElementData(string sElementName, string myValue){
        
	if( sElementName == "property" ){
		addProperty(myValue);
	}
	else if( sElementName == "name" ){
		setName(myValue);
	}
	else if( sElementName == "displayChar" ){
		if( myValue.length() > 0 )
			setDisplayChar(myValue[0]);
	}
}


void Entity::addProperty(string myProperty){
	myProperties.push_back(myProperty);
}

void Entity::writeFragment(ostream & output){
	output << "  <Entity>" << endl;
	writeDataAsFragment(output);
	output << "  </Entity>" << endl;
}

void Entity::writeDataAsFragment(ostream & output){
	XMLSerializable::writeDataAsFragment(output);
    
	output << "      <name>" << getName() << "</name>" << endl;
	output << "      <displayChar>" << getDisplayChar() << "</displayChar>" << endl;
}


void Entity::setName(string name)
{
    myName = name;
}
char Entity::getDisplayChar()
{
    return myDisplay;
}

void Entity::setDisplayChar(char displayChar)
{
    myDisplay = displayChar;
}


void Entity::setYX(int y, int x){
    myX = y;
    myY = x;
}

int Entity::getX(){
    
    return myX;
}

int Entity::getY(){
 
    return myY;
}


