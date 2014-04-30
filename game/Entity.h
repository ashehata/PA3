//
//  Entity.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Entity__
#define __pa1_1__Entity__

#include <iostream>
#include <string>
#include "XMLSerializable.h"
#include <fstream>
#include <vector>
using namespace::std;
class Entity: public XMLSerializable 
{
    
public:
    
    Entity();
    void addProperty(string myProperty);
    virtual string getName();
    virtual void setName(string name);
    virtual char getDisplayChar();
    virtual void setDisplayChar(char displayChar);
	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);
    virtual void setYX(int y, int x);
    virtual int getX();
    virtual int getY();
private:
    int myX;
    int myY;
    string myName;
    char myDisplay;
    vector<string> myProperties;
    
    
};



#endif /* defined(__pa1_1__Entity__) */
