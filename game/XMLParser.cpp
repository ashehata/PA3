//
//  XMLParser.cpp
//  pa1.2
//
//  Created by Aly Shehata on 2/23/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "XMLParser.h"
#include <map>
#include <functional>
#include "Item.h"
#include "Enemy.h"
#include "Armor.h"
#include "Weapon.h"
#include "Consumable.h"
void  XMLParser::outputXML(vector<XMLSerializable*> & vObjects, ostream & output)
{
    output << "<?xml version=\"1.0\" encoding = \"utf-8\"?>"
    << endl
    << "<World>"
    << endl;
    
    for( auto it = vObjects.begin(); it != vObjects.end(); it++ )
    {
        (*it)->writeFragment(output);
    }
    output << "</World>" << endl;
}


void XMLParser::dumpObjects(vector<XMLSerializable*> & vObjects)
{
    for( auto it = vObjects.begin(); it != vObjects.end(); it++)
    {
        (*it)->dumpObject();
        cout << endl;
    }
    
}


void XMLParser::parseElement(istream & input, string sPrefix, vector<XMLSerializable*> & vObjects, int &index)
{
	string sElementName;
	getline(input, sElementName, '>');
	//cout << sPrefix << sElementName << " (start)" << endl;
    map<string,function<XMLSerializable*()>> mapConstructor;
    mapConstructor["Item"] = []() { return new Item; };
    mapConstructor["Enemy"] = []() { return new Enemy; };
    mapConstructor["Armor"] = []() { return new Armor; };
    mapConstructor["Weapon"] = []() { return new Weapon; };
    mapConstructor["Consumable"] = []() { return new Consumable; };
    function<XMLSerializable*()> pFunc;
    XMLSerializable* myObject = NULL;
    
    if (sPrefix == "-> ")
    {
        index++;
        pFunc = mapConstructor[sElementName];
        myObject = pFunc();
        vObjects.push_back(myObject);
    }
    
    
	bool bDone = false;
    
	string sContent;
    
	while( !bDone )
	{
        string sEndTag;
		char c = input.get();
		if( c == '<' )
		{
			if( input.peek() == '/' )
			{
				getline(input, sEndTag, '>');
                
				if( sEndTag == "/" + sElementName )
				{
                    
				//	cout << sPrefix << sElementName << ": " << sContent << " (end)" << endl;
                    
                    if (sPrefix == "-> -> ")
                    {
                        vObjects[index]->setElementData(sElementName, sContent);
                    }
                    bDone = true;
                    
				}
				else
				{
					cout << "Inavlid XML!" << endl;
				}
			}
			else
			{
				parseElement(input, sPrefix + "-> ", vObjects, index);
			}
		}
		else if( c != '\n' )
		{
			sContent.push_back(c);
		}
	}
    if (myObject != NULL)
    {
    }
	return;
}

void XMLParser::parseXML(istream & input, vector<XMLSerializable*> & vObjects)
{
    vector<XMLSerializable*> myWorld;
	while(input.get() != '<')
	{
	}
    
	if( input.get() != '?' )
	{
		cout << "Invalid header" << endl;
		return;
	}
    
	while( input.get() != '?')
	{
	}
    
    
	if( input.get() != '>')
	{
        cout << "Invalid header" << endl;
        return ;
	}
    
	while(input.get() != '<')
	{
	}
    int index = -1;
	parseElement(input, "", vObjects, index );
}