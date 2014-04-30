//
//  XMLParser.h
//  pa1.2
//
//  Created by Aly Shehata on 2/23/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef pa1_2_XMLParser_h
#define pa1_2_XMLParser_h

#include <ostream>
#include <vector>
#include "XMLSerializable.h"
class XMLParser{
public:
    void  outputXML(vector<XMLSerializable*> & vObjects, ostream & output);
    void dumpObjects(vector<XMLSerializable*> & vObjects);
    void parseElement(istream & input, string sPrefix, vector<XMLSerializable*> & vObjects, int &index);
    void parseXML(istream & input, vector<XMLSerializable*> & vObjects);

    
    
private:
    
};


#endif
