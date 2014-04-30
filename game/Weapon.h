//
//  Weapon.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Weapon__
#define __pa1_1__Weapon__

#include <iostream>
#include "Item.h"

class Weapon:public Item{
    
public:
    Weapon();
    int getDamage();
    void setDamage(int damage);
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
    int myDamage;
    string myType;
    int myX;
    int myY;
    
};


#endif /* defined(__pa1_1__Weapon__) */
