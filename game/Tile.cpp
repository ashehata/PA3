//
//  Tile.cpp
//  pa1.2
//
//  Created by Aly Shehata on 3/15/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Tile.h"


    
    
Tile::Tile ()
{
    myChar = ' ';
}
Tile::Tile (char tileChar)
{
    myChar = tileChar;
}

void Tile::setDisplayChar(char tileChar)
{
    if (tileChar == '\0')
    {
        myChar = ' ';
        return;
    }
    myChar = tileChar;
    
}
char Tile::getDisplayChar()
{
    char* aPointer = &myChar;
    if (aPointer == nullptr)
        return ' ';
    return myChar;
    
}
    
