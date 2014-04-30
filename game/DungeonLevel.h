//
//  DungeonLevel.h
//  pa1.2
//
//  Created by Aly Shehata on 3/15/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#ifndef __pa1_2__DungeonLevel__
#define __pa1_2__DungeonLevel__

#include <iostream>
#include <vector>
#include "Tile.h"
#include <random>
#include <ctime>
using namespace std;
class DungeonLevel{
public:
    
    DungeonLevel(int myWidth, int myHeight, std::mt19937 & randomGen);
    vector<vector<Tile>> getLevel();
	void dump();
    void constructLevel(int myWidth, int myHeight, std::mt19937 & randomGen);
    bool testLevel(vector<vector<Tile>> &myTiles, DungeonLevel &test);
    vector<vector<char>> getLevelChars();
private:
    vector<vector<Tile>> myTiles;
    int height, width;
};

#endif /* defined(__pa1_2__DungeonLevel__) */
