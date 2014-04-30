#ifndef _XMLSerializable_Included_
#define _XMLSerializable_Included_

#include <string>
#include <iostream>
#include <istream>
using namespace::std;
class XMLSerializable
{
public:
	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);


};

#endif

