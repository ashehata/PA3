#include "Item.h"
#include <string>

using namespace std;

Item::Item()
{

    myWeight = 0;
    myValue = 0;
    myQuantity = 0;
    pickedUp = false;
    
}

int Item::getWeight()
{
    return myWeight;
    
}
void Item::setWeight(int weight)
{
    
    myWeight = weight;
    
}
int Item::getValue()
{
    return myValue;
    
}
void Item::setValue(int value)
{
    myValue = value;
    
}
int Item::getQuantity()
{
    return myQuantity;
    
}
void Item::setQuantity(int quantity)
{
    myQuantity = quantity;
    
}


void Item::use(Unit &user)
{
    
}







void Item::dumpObject()
{
    cout << "Item:" << endl;
    dumpObjectData();
}
void Item::dumpObjectData()
{
    Entity::dumpObjectData();
    cout << "       Value: " << getValue() ;
    cout << "   Weight: "<< getWeight();
    cout << "   Quantity: " << getQuantity() << endl;
}

void Item::writeFragment(std::ostream & output)
{
    output << "  <Item>" << endl;
    writeDataAsFragment(output);
    output << "  </Item>" << endl;
    
}
void Item::writeDataAsFragment(std::ostream & output)
{
        Entity::writeDataAsFragment(output);
        output << "      <weight>" << getWeight() << "</weight>" << endl;
        output << "      <value>" << getValue() << "</value>" << endl;
        output << "      <quantity>" << getQuantity() << "</quantity>" << endl;
    
}
void Item::setElementData(string myElementName, string myValue)
{
    
    Entity::setElementData(myElementName, myValue);
	if( myElementName == "weight" ){
		setWeight(atoi(myValue.c_str()));
	}
	else if( myElementName == "value" ){
		setValue(atoi(myValue.c_str()));
	}
	else if( myElementName == "quantity" ){
		setQuantity(atoi(myValue.c_str()));
	}
    
}

void Item::setYX(int y, int x){
    myX = y;
    myY = x;
    
}

int Item::getX(){
    
    return myX;
}

int Item::getY(){
    
    return myY;
}


bool Item::isPickedUp()
{
    return pickedUp;
}
void Item::setPickedUp(bool value)
{
    pickedUp = value;
}




