//
//  Armor.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Armor__
#define __pa1_1__Armor__

#include <iostream>
#include "Item.h"

class Armor: public Item
{
public:
    Armor();
    int getProtection();
    void setProtection(int protection);
    string getType();
    void setType(string type);
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
    int myProtection;
    string myType;
    
    
};

#endif /* defined(__pa1_1__Armor__) */
