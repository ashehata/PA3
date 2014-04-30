//
//  Tile.h
//  pa1.2
//
//  Created by Aly Shehata on 3/15/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef pa1_2_Tile_h
#define pa1_2_Tile_h


class Tile
{
public:
    
    
    Tile ();
    Tile (char tileChar);
    void setDisplayChar(char tileChar);
    char getDisplayChar();
    
    
private:
    
    char myChar;
    
    
    
    
};

#endif
