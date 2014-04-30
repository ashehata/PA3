#ifndef _Item_included_
#define _Item_included_

#include <string>
#include "Entity.h"
#include "Unit.h"

using namespace::std;

class Item: public Entity
{
public:
    Item();
    virtual int getWeight();
    virtual void setWeight(int weight);
    virtual int getValue();
    virtual void setValue(int value);
    virtual int getQuantity();
    virtual void setQuantity(int quantity);
    virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);
    virtual void use(Unit & user);
    virtual void setYX(int y, int x);
    virtual int getX();
    virtual int getY();
    virtual bool isPickedUp();
    virtual void setPickedUp(bool value);
	
private:
    int myX;
    int myY;
    int myWeight;
    int myValue;
    int myQuantity;
    bool pickedUp;

};

#endif