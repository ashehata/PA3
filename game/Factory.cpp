//
//  Factory.cpp
//  pa3
//
//  Created by Aly Shehata on 4/25/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Factory.h"
#include "curses.h"

Factory & Factory::Instance()
{
    static Factory factory;
    
    return factory;
}


Factory::Factory()
{
    rand.seed(time(NULL));
    ifstream input;
    input.open("world.xml");
    vector<XMLSerializable*> myObjects;
    XMLParser myParse;
    myParse.parseXML(input, myObjects);

    for( auto it = myObjects.begin();
        it != myObjects.end();
        it++ )
    {
        Unit* myUnit = dynamic_cast<Unit*>(*it);
		Item* myItem = dynamic_cast<Item*>(*it);
		Weapon* myWeapon = dynamic_cast<Weapon*>(*it);
        Armor* myArmor = dynamic_cast<Armor*>(*it);
        if(myUnit != NULL)
        {
            myUnits.push_back(myUnit);
        }
        
		if(myWeapon != NULL)
		{
			myWeapons.push_back(myWeapon);
		}
        
        if(myItem != NULL)
        {
            myItems.push_back(myItem);
        }
        if(myArmor != NULL)
        {
            myItems.push_back(myItem);
        }
        
    }
}


Unit* Factory::generateUnit(int maxLevel){
    vector<Unit*> myGameUnits;
    for (auto it = myUnits.begin(); it!= myUnits.end();it++)
    {
        if ((*it)->getLevel()<=maxLevel)
        {
            myGameUnits.push_back(*it);
        }
    }
    if(myGameUnits.size() != 0)
    {
        int index = (rand() % myGameUnits.size());
        Unit* myUnit = myGameUnits[index];
        
        Unit* pReturnValue = new Unit(*myUnit);
        
		pReturnValue->addItem(generateWeapon());
        
        return pReturnValue;
    }
    
    return NULL;
}
Item* Factory::generateItem(){
    vector<Item*> tempItems;
    
    for(auto it = myItems.begin(); it != myItems.end(); it++){
		tempItems.push_back((*it));
    }
    
	int randomItem = (rand() % (myItems.size() - 1));
    
    
    //	Item * pItem = tempItems.at(randomItem);
    
    //	Item * pReturnValue = new Item(*pItem);
    
    //	return pReturnValue;
	return tempItems.at(randomItem);

}


/*Item* Factory::generateArmor(){
    
    
}*/
Weapon* Factory::generateWeapon(){
    vector<Weapon*> myGameWeapons;
    
    for(auto it = myWeapons.begin();
        it != myWeapons.end();
        it++)
    {
        //need something here to validate proper item
        myGameWeapons.push_back(*it);
    }
    
    if(myGameWeapons.size() != 0)
    {
        int index = (rand() % myGameWeapons.size());
        Weapon* w_Weapon = myGameWeapons[index];
        
        Weapon* pReturnValue = new Weapon(*w_Weapon);
        return pReturnValue;
    }
    
    return NULL;
    
}



Factory::~Factory(){

}

