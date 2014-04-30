//
//  Enemy.h
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_1__Enemy__
#define __pa1_1__Enemy__

#include <iostream>
#include "Unit.h"
class Enemy: public Unit
{
public:
    Enemy();
    bool isHostile();
    void setHostile(bool value);
    void takeTurn();
    //

    
    virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);
    
private:
    
    bool hostile;
    
    
    
    
};


#endif /* defined(__pa1_1__Enemy__) */
