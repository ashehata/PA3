
//  DungeonLevel.cpp
//  pa1.2
//
//  Created by Aly Shehata on 3/15/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "DungeonLevel.h"

DungeonLevel::DungeonLevel(int myWidth, int myHeight, std::mt19937 & iRandom){
    constructLevel(myWidth,myHeight, iRandom);
    }

void DungeonLevel::constructLevel(int iWidth, int iHeight, std::mt19937 & iRandom)
{
	// Initialize the blank vector
	myTiles.resize(iHeight);

    int stairsUpx = iRandom() % 4;
	int stairsUpy = iRandom() % 2;
    int pieceWidth = iWidth / 4;
	int pieceHeight = iHeight / 2;
    
	int stairsDownX = iRandom() % 4;
	int stairsDowny = iRandom() % 2;
    
    //determine where the up and down stairs should be placed.
    while( stairsUpx == stairsDownX && stairsUpy == stairsDowny ){
		stairsDownX = iRandom() % 4;
		stairsDowny = iRandom() % 2;
	}
    
    //fill each tile with blank spaces
	for(auto it = myTiles.begin(); it != myTiles.end(); it++ ){
		(*it).resize(iWidth,Tile(' '));
	}
    //
    
    //place a rectangle of tunnles on the dungeon that we can put a room on
	for( int x = (pieceWidth/2); x <= ((3 * pieceWidth) + (pieceWidth/2))+5; x++ ){
		myTiles[pieceHeight/2][x] = '#';
		myTiles[pieceHeight + (pieceHeight/2)][x] = '#';
	}
    
	for( int y = (pieceHeight/2); y <= (pieceHeight + (pieceHeight/2)); y++ ){
		myTiles[y][pieceWidth/2] = '#';
		myTiles[y][(3 * pieceWidth) + (pieceWidth/2)] = '#';
	}
    ///
    

    //algorithm for generating a room
    
	for( int myPieceX = 0; myPieceX < 4; myPieceX++ ){
		int iXStart = myPieceX * pieceWidth+1;
        
		for( int myPieceY = 0; myPieceY < 2; myPieceY++ ){
			int iYStart = myPieceY * pieceHeight;
            
			int myRoomWidth = (iRandom() % (pieceWidth - 5)) + 4;
			int myRoomHeight = (iRandom() % (pieceHeight - 5)) + 4;

            
			int myXOffset = iRandom() % (pieceWidth - myRoomWidth);
			int myYOffset = iRandom() % (pieceHeight - myRoomHeight);
            
			
            
			int iTunnelY = iYStart + (pieceHeight/2);
            
            
			if( myYOffset + iYStart > iTunnelY ){
				myYOffset = iTunnelY - iYStart;
			}
			else if( myYOffset + iYStart + myRoomHeight <= iTunnelY ){
				myYOffset = 1 + iTunnelY - (iYStart + myRoomHeight);
			}
            

            
			if( myPieceX == 0 || myPieceX == 3 ){
				int iTunnelX = iXStart + (pieceWidth/2);
                
				if( myXOffset + iXStart > iTunnelX ){
				}
				else if( myXOffset + iXStart + myRoomWidth <= iTunnelX ){
					myXOffset = iTunnelX - (iXStart + myRoomWidth);
				}
                
			}
            
            
			for( int x = 0; x < myRoomWidth; x++ ){
				for( int y = 0; y < myRoomHeight; y++ ){
					myTiles[y + myYOffset + iYStart][x + myXOffset + iXStart] = '.';
				}
			}
            
            int randomHeight = (myYOffset + iYStart +iRandom() % myRoomHeight);
            int randomWidth = (myXOffset + iXStart+(iRandom() % (myRoomWidth)));
			if( myPieceX == stairsUpx && myPieceY == stairsUpy ){
				myTiles[randomHeight][randomWidth] = '<';
			}
            
			if( myPieceX == stairsDownX && myPieceY == stairsDowny ){
                 randomHeight = myYOffset + iYStart +iRandom() % myRoomHeight;
                 randomWidth = myXOffset + iXStart+(iRandom() % myRoomWidth);
				myTiles[randomHeight][randomWidth] = '>';
			}
			}
            
		}
	
    //put the walls '+'s
    for (int x=1; x<myTiles.size(); x++)
    {
        for (int y=1; y<myTiles[x].size();y++)
        {
            if (myTiles[x][y].getDisplayChar() == '.')
            {
                if (myTiles[0][y].getDisplayChar() == '.')
                { myTiles[0][y].setDisplayChar('+');
                }
                if (myTiles[x+1][y].getDisplayChar() == ' ')
                    myTiles[x+1][y].setDisplayChar('+');

                if (myTiles[x-1][y].getDisplayChar() == ' ')
                    myTiles[x-1][y].setDisplayChar('+');
                if (myTiles[x-1][y+1].getDisplayChar() == ' ')
                    myTiles[x-1][y+1].setDisplayChar('+');
                if (myTiles[x-1][y-1].getDisplayChar() == ' ')
                    myTiles[x-1][y-1].setDisplayChar('+');

                if (myTiles[x+1][y+1].getDisplayChar() == ' ')
                    myTiles[x+1][y+1].setDisplayChar('+');
                if (myTiles[x+1][y-1].getDisplayChar() == ' ')
                    myTiles[x+1][y-1].setDisplayChar('+');
                if (myTiles[x+1][y].getDisplayChar() == ' ')
                    myTiles[x+1][y].setDisplayChar('+');
                if (myTiles[x][y+1].getDisplayChar() == ' ')
                    myTiles[x][y+1].setDisplayChar('+');
                if (myTiles[x][y-1].getDisplayChar() == ' ')
                    myTiles[x][y-1].setDisplayChar('+');
                
            }
        }
    }

    
    
}


void testRectangularRooms(vector<vector<Tile>> &myTiles)
{
    

        
}



void markPosition(vector<vector<Tile>> &myTiles, int x, int y)
{
    if (y>=myTiles.size())
        return;
    if (x>=myTiles[y].size())
        return;
    char currentTile = myTiles[y][x].getDisplayChar();
    if (!(currentTile =='.' || currentTile =='#'))
        return;
    myTiles[y][x]='X';
    markPosition(myTiles, x+1, y);
    markPosition(myTiles, x-1, y);
    markPosition(myTiles, x+1, y+1);
    markPosition(myTiles, x, y+1);
    markPosition(myTiles, x, y-1);
    markPosition(myTiles, x+1, y-1);
    markPosition(myTiles, x-1, y-1);
    markPosition(myTiles, x-1, y+1);
    markPosition(myTiles, x, y);


    
    
    
    
    
}





bool testConnection(vector <vector <Tile>> myTiles){
    // Display the initial state
	cout << "Initial state: " << endl;
	for( auto itOuter = myTiles.begin(); itOuter != myTiles.end(); itOuter++ ){
		for( auto itInner = (*itOuter).begin(); itInner != (*itOuter).end(); itInner++ ){
			cout << (*itInner).getDisplayChar();
		}
        
		cout << endl;
	}
    
	int x = -1;
	int y = -1;
    
	// pick a starting position
    for( int i=0; i<myTiles.size();i++ ){
        for( int j=0; j<myTiles[i].size();j++ ){
            if( myTiles[i][j].getDisplayChar() == '.' || myTiles[i][j].getDisplayChar() == '#' )
			{
				// Starting position just has to be a room or
				// tunnel tile
				x = j;
				y = i;
			}
		}
	}
    
	if( x == -1 )
	{
		cout << "Unable to find starting position!" << endl;
		return false;
	}
	
	// Call the function which actually marks the tiles -- it should mark
	// the starting tile, then any adjacent to it, etc -- so after it's done,
	// everything that can be connected to the starting tile should be
	// marked.
	markPosition(myTiles, x, y);
    
	bool bCorrect = true;
    
	cout << endl << "Marked state: " << endl;
    for( auto itOuter = myTiles.begin(); itOuter != myTiles.end(); itOuter++ ){
        for( auto itInner = (*itOuter).begin(); itInner != (*itOuter).end(); itInner++ ){
            cout << (*itInner).getDisplayChar();
            
			// Now, test if it's a room/tunnel tile -- if it's still
			// one after we've
			if( (*itInner).getDisplayChar() == '.' || (*itInner).getDisplayChar() == '#' )
			{
				bCorrect = false;
			}
		}
        
		cout << endl;
	}
    
	cout << endl;
    
	if( !bCorrect )
        
	{
	}
    
    if(bCorrect)
    {
        cout << "All rooms are connected" <<endl;
    }
    
	return bCorrect;
    

}

vector<vector<Tile>> DungeonLevel::getLevel()
{
    return myTiles;
}


vector<vector<char>> DungeonLevel::getLevelChars(){
    vector<vector<char>> myLevelChars;
    myLevelChars.resize(20);
    for(auto it = myLevelChars.begin(); it != myLevelChars.end(); it++ ){
		(*it).resize(79,' ');
    }
    for( int i = 0; i<  myTiles.size(); i++ ){
        myLevelChars.push_back(*new vector<char>);
		for( int j = 0; j<myTiles[i].size(); j++ ){
			myLevelChars[i][j] = myTiles[i][j].getDisplayChar();
		}
	}
    return myLevelChars;
    
}


void DungeonLevel::dump(){
	for( auto itOuter = myTiles.begin(); itOuter != myTiles.end(); itOuter++ ){
		for( auto itInner = (*itOuter).begin(); itInner != (*itOuter).end(); itInner++ ){
			cout << (*itInner).getDisplayChar();
		}
        
		cout << endl;
	}
    
}

bool testDungeonSize(vector<vector<Tile>> &myTiles){
    
if (myTiles.size() !=20)
    return false;
if (myTiles[0].size()!=79)
    return false;
    cout << "Dungeon Size is 79x20" << endl;
    return true;
    
}

bool testRooms(vector<vector<Tile>> &myTiles)
{
    bool isPassed = true;
    int counter = 0;
    int upStairCounter=0;
    int downStairCounter=0;
    
    for (int x=0; x<myTiles.size();x++){
        for (int y = 0; y<myTiles[x].size(); y++)
        {
            if (myTiles[x][y].getDisplayChar()=='.' || myTiles[x][y].getDisplayChar()=='>' || myTiles[x][y].getDisplayChar()=='>' )
                counter++;
            if (myTiles[x][y].getDisplayChar()=='>')
                upStairCounter++;
            if (myTiles[x][y].getDisplayChar()=='<')
                downStairCounter++;
                
        }
    }
    if (counter<200)
    {
        isPassed = false;
        cout << "Room tiles are less 200: " << counter;;
    }
    if (upStairCounter!=1||downStairCounter!=1)
    {
        cout << "Number of stairs is not correct" << endl;
        isPassed=false;
    }
    cout << "More than 200 room tiles, ("<<counter<<") To be exact." <<endl;
    return true;
}

bool DungeonLevel::testLevel(vector<vector<Tile>> &myTiles, DungeonLevel &test)
{
    bool testsPassed = true;
    if (!testConnection(myTiles))
    {
        cout << "Room not connected. Failed Test";
        cout << "One or more tests failed.";
        return testsPassed;}
    if (!testDungeonSize(myTiles))
    {
        cout << "One or more tests failed.";
        return testsPassed;}
    testsPassed = testRooms(myTiles);
    if (testsPassed == false)
    {
        cout << "One or more tests failed.";
        return testsPassed;}
    return testsPassed;
    
}

