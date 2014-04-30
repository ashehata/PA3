//
//  Game.cpp
//  pa3
//
//  Created by Aly Shehata on 4/23/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Game.h"
#include "Unit.h"
#include <sstream>
Game::Game(){
    myGameUnits.resize(50); //50 elements containing vector<Unit*>
    myGameItems.resize(50); //same ^
    currentArmor = "N/A";
    currentProtection = 0;
    currentWeapon = "N/A";
    currentDamage = 1;
    dlvl = 0;
    mt.seed(time(NULL));
    initialState();
}


void Game::initialState(){
    for (int i=0;i<50;i++){
        myLevels.push_back(*new DungeonLevel(79,20,mt));
        }
    currentLevelChars = myLevels[dlvl].getLevelChars();
    myMoves = 0;
    initscr();
    generateUnits();
    generateItems();
    playGame();
}

void Game::generateUnits(){
    for (int dungeons=0;dungeons<myLevels.size();dungeons++){
    int x;
    int y;
    for (int i=0; i<(dungeons*2)+3;i++)
    {
        Unit* currentUnit = Factory::Instance().generateUnit(i+1);
        myGameUnits[dungeons].push_back(currentUnit);
    }
    
    for (int i =0; i<myGameUnits[dungeons].size();i++)
    {
        do {
            x = rand()%78;
            y = rand()%19;
        }
        while (myLevels[dungeons].getLevelChars()[y][x] != '.' );
        myGameUnits[dungeons][i]->setYX(x, y);
    }

    }
    
 
}

void Game::generateItems(){
    for (int dungeons=0;dungeons<myLevels.size();dungeons++){
        int x = rand()%78;
        int y = rand()%19;
        for (int i=0; i<(dungeons*2)+2;i++)
        {
            Item* currentItem = Factory::Instance().generateItem();
            myGameItems[dungeons].push_back(currentItem);
        }
        for (int i =0; i<myGameItems[dungeons].size();i++)
        {
            do {
                x = rand()%78;
                y = rand()%19;
            }
            while (myLevels[dungeons].getLevelChars()[y][x] != '.' );
            myGameItems[dungeons][i]->setYX(x, y);
        }
    }
}

void Game::playGame()
{
    noecho();
    keypad(stdscr, TRUE);
    insertPlayer();
    drawLevel();
    while(takeTurn()){
    }
}


bool Game::takeTurn(){
    stringstream output;
    if (myMoves%100==0) //regenerate health every 100 moves
    {
        myPlayer.setHealth((myPlayer.getHealth()+myPlayer.getHealth()/10)); //regenerate 1/10th hp every 40 moves
        move(23,0);
        stringstream output;
        output << "Acquired " << myPlayer.getHealth()/5 << "Health.";
    }
    Item* currentItem;
    moveUnits();
    currentItem = checkItems();
    if (dlvl<0){
        clear();
        addstr("You went out of the dungeons. Your lack of courage is nothing to be ashamed of.\nPress any key to continue.");
        getch();
        return false;
    }
    int input;
    input = getch();
    
    if (input == KEY_UP)
    {
        moveUnit("up", &myPlayer);
    }
    else if (input == KEY_DOWN)
    {
        moveUnit("down", &myPlayer);
    }
    if (input == KEY_LEFT)
    {
        moveUnit("left", &myPlayer);
    }
    if (input == KEY_RIGHT)
    {
        moveUnit("right", &myPlayer);
    }
    if (input == ','){
        goUp();
    }
    
    if (input =='.')
    {
        goDown();
    }
    
    if (input == 'p')
    {
        if (currentItem==NULL)
        {
            output << "No Item to pickup here.";
        }
        else
        {
			Armor* a_Temp = dynamic_cast<Armor*>(currentItem);
			Weapon* w_Temp = dynamic_cast<Weapon*>(currentItem);
            
            if (a_Temp != NULL)
            {
                if (myPlayer.getArmor() == NULL)
                {
                    myPlayer.setArmor(a_Temp);
                    output << "\nYou picked up a " << a_Temp->getName() << " Armor. (+" << a_Temp->getProtection()<<"HP)";
                    myPlayer.setHealth(myPlayer.getHealth()+a_Temp->getProtection());
                    for (int i=0;i<myGameItems[dlvl].size();i++)
                    {
                        if (myGameItems[dlvl][i]==currentItem){
                            currentItem->setPickedUp(true);
                            drawLevel();
                            myGameItems[dlvl].erase(myGameItems[dlvl].begin()+i);
                            
                    }
                }
                

                }
                else{
                    Armor* oldArmor = myPlayer.getArmor();
                    oldArmor->setYX(a_Temp->getX(),a_Temp->getY());
                    myGameItems[dlvl].push_back(oldArmor);
                    myPlayer.setArmor(a_Temp);
                    oldArmor->setPickedUp(false);
                    output << "\nYou picked up a " << a_Temp->getName() << " Armor. (+" << a_Temp->getProtection()<<"HP)";
                    addstr(output.str().c_str());
                    myPlayer.setHealth(myPlayer.getHealth()+a_Temp->getProtection());
                    for (int i=0;i<myGameItems[dlvl].size();i++)
                    {
                        if (myGameItems[dlvl][i]==currentItem){
                            currentItem->setPickedUp(true);
                            drawLevel();
                            myGameItems[dlvl].erase(myGameItems[dlvl].begin()+i);
                            }

                        }
                }
            }
                else if (w_Temp != NULL)
                {
                    if (myPlayer.getWeapon() == NULL)
                    {
                        myPlayer.setWeapon(w_Temp);
                        output << "\nYou picked up a " << w_Temp->getName() << " Weapon. (+" << w_Temp->getDamage()<<" Damage)";
                        addstr(output.str().c_str());
                       // myPlayer.setHealth(myPlayer.getHealth()+a_Temp->getProtection());
                        for (int i=0;i<myGameItems[dlvl].size();i++)
                        {
                            if (myGameItems[dlvl][i]==currentItem){
                                currentItem->setPickedUp(true);
                                drawLevel();
                                myGameItems[dlvl].erase(myGameItems[dlvl].begin()+i);
                                
                            }
                        }
                        
                        
                    }
                    else{
                        Weapon* oldWeapon = myPlayer.getWeapon();
                        oldWeapon->setYX(w_Temp->getX(),w_Temp->getY());
                        myGameItems[dlvl].push_back(oldWeapon);
                        myPlayer.setWeapon(w_Temp);
                        oldWeapon->setPickedUp(false);
                        output << "\nYou picked up a " << w_Temp->getName() << " Weapon. (+" << w_Temp->getDamage()<<" Damage)";
                        addstr(output.str().c_str());
                        //myPlayer.setHealth(myPlayer.getHealth()+a_Temp->getProtection());
                        for (int i=0;i<myGameItems[dlvl].size();i++)
                        {
                            if (myGameItems[dlvl][i]==currentItem){
                                currentItem->setPickedUp(true);
                                drawLevel();
                                myGameItems[dlvl].erase(myGameItems[dlvl].begin()+i);
                            }
                            
                        }
                    }
                }
            move(22,0);
            addstr(output.str().c_str());
        }
        
            

    
    }
    //F1 to quit
    if (input == KEY_F(1)){
        return false;
    }
    
    if (input == 'i')
    {
        displayInventory();
    }
    return true;
}



Item* Game::checkItems()
{
    for (int i = 0; i<myGameItems[dlvl].size();i++)
    {
        Item* currentItem = myGameItems[dlvl][i];
        int iX1 = currentItem->getX();
		int iY1 = currentItem->getY();
		int iX2 = myPlayer.getX();
		int iY2 = myPlayer.getY();
        int dist = sqrt(pow((iX2 - iX1),2) + pow((iY2 - iY1),2));
        if((dist >= -1)&&(dist <= 1))
        {
            move(22,0);
            stringstream output;
            output << "You have found a " << currentItem->getName() << ". [p] Pick up";
            addstr(output.str().c_str());
            return currentItem;
        }
        
    }
    
    return NULL;
    
}



void Game::moveUnits(){
    myMoves ++;//everytime unit moves, player must've move.
    for (int i = 0; i<myGameUnits[dlvl].size();i++)
    {
        Unit* currentUnit = myGameUnits[dlvl][i];
        int iX1 = currentUnit->getX();
		int iY1 = currentUnit->getY();
		int iX2 = myPlayer.getX();
		int iY2 = myPlayer.getY();
        int dist = sqrt(pow((iX2 - iX1),2) + pow((iY2 - iY1),2));
        if((dist >= -1)&&(dist <= 1))
        {
            attack(currentUnit);
        }
        else if(dist <= 10)
		{
			if(iX1 > iX2)
				moveUnit("left", currentUnit);
			else
				moveUnit("right", currentUnit);
			if(iY1 > iY2)
				moveUnit("up", currentUnit);
			else
				moveUnit("down", currentUnit);
		}
        if (currentUnit->getHealth()==0)
        {
            myPlayer.setExperience(myPlayer.getExperience()+currentUnit->getLevel());
            currentUnit->setDisplayChar('.');
            drawLevel();
            myGameUnits[dlvl].erase(myGameUnits[dlvl].begin()+i);
        }

    }
}

void Game::attack(Unit *myUnit){
    move(22,0);
    stringstream output;
    output << "You are being attacked by a level " <<myUnit->getLevel()<<" "<< myUnit->getName()<< "[" << myUnit->getHealth() <<"HP]. Stand your ground and fight, or run.";
    addstr(output.str().c_str());
    if(myUnit->getLevel()>currentProtection){
    myPlayer.setHealth(myPlayer.getHealth() - (myUnit->getLevel()-currentProtection));
    }
    else {
        myPlayer.setHealth((myPlayer.getHealth()+currentProtection)-(myUnit->getLevel()));
    }
    myUnit->setHealth(myUnit->getHealth() - myPlayer.getLevel());
}
void Game::goUp(){
    int x = myPlayer.getX();
    int y = myPlayer.getY();
    char currentTile = myLevels[dlvl].getLevelChars()[y][x];
    if (currentTile=='<'){
        dlvl--;
        if (dlvl<0) // return if went outside dugeons...
        {
            return;
        }
        currentLevelChars = myLevels[dlvl].getLevelChars();
        insertPlayer();
        drawLevel();

}
    else{
        addstr("No upstairs here");
    }
}


void Game::goDown(){
    int x = myPlayer.getX();
    int y = myPlayer.getY();
    char currentTile = myLevels[dlvl].getLevelChars()[y][x];
    if (currentTile=='>'){
        dlvl++;
        currentLevelChars = myLevels[dlvl].getLevelChars();
        currentLevelChars = myLevels[dlvl].getLevelChars();
        insertPlayer();
        drawLevel();

    }
    else
    {
        addstr("No downstairs here");
    }
    
}
void Game::insertPlayer(){
    int xStairUp = 0;
    int yStairUp = 0;
    for (int i=0; i<currentLevelChars.size();i++)
    {
        for(int j=0; j<currentLevelChars[i].size();j++){
            if(currentLevelChars[i][j]=='<')
            {
                xStairUp =i;
                yStairUp=j;
            }
        }
    }
    currentLevelChars[xStairUp][yStairUp] = '@';
    myPlayer.setYX(yStairUp, xStairUp);
}

void Game::drawLevel(){
    clear();
    string currentLevel="";
    stringstream gameStatus;
    for (int i =0; i <myGameUnits[dlvl].size();i++){
        int x = myGameUnits[dlvl][i]->getX();
        int y = myGameUnits[dlvl][i]->getY();
        if (myGameUnits[dlvl][i]->getHealth()!=0) //don't display dead monsters
        {
            currentLevelChars[y][x] = myGameUnits[dlvl][i]->getDisplayChar();
        }
        else
        {
            currentLevelChars[y][x] = myLevels[dlvl].getLevelChars()[y][x];
        }
    }
    for (int i =0; i <myGameItems[dlvl].size();i++){
        int x = myGameItems[dlvl][i]->getX();
        int y = myGameItems[dlvl][i]->getY();
        if (!myGameItems[dlvl][i]->isPickedUp()){ //if item isn't picked up, display it.
            currentLevelChars[y][x] = myGameItems[dlvl][i]->getDisplayChar();
        }
        else{
            currentLevelChars[y][x] = myLevels[dlvl].getLevelChars()[y][x];
        }
        }
        
    for (int i=0; i<currentLevelChars.size();i++)
    {
        for (int j=0; j<currentLevelChars[i].size();j++)
        {
            currentLevel += currentLevelChars[i][j];
        }
        currentLevel+="\n";
    }
    

    addstr(currentLevel.c_str());
//    int x = myPlayer.getX();
//    int y = myPlayer.getY();
//    string xPos = "x: " + to_string(x);
//    string yPos = "y: " + to_string(y);
//    addstr(xPos.c_str());
//    addstr(yPos.c_str());
    move(19,0);
    if (myPlayer.getArmor()!=NULL)
    {
        currentArmor = myPlayer.getArmor()->getName();
        currentProtection = myPlayer.getArmor()->getProtection();
        
    }
    if (myPlayer.getWeapon()!=NULL)
    {
        currentWeapon = myPlayer.getWeapon()->getName();
        currentDamage = myPlayer.getLevel() + myPlayer.getWeapon()->getDamage();
        
    }
    
    gameStatus << "Health: " << myPlayer.getHealth() << " XP: " << myPlayer.getExperience() << " Level:" << myPlayer.getLevel() << " Dungeon Level:" << dlvl+1 <<"\n"<<"Armor: "<<currentArmor<<"(Protection:"<<currentProtection<<") Weapon: "<<currentWeapon<<"(Damage: "<<currentDamage<< ")\n[F1]Quit\t";
    addstr(gameStatus.str().c_str());
}


void Game::moveUnit(string direction, Unit* myUnit ){
    bool enemyClose = false;
    int x = myUnit -> getX();
    int y = myUnit -> getY();
    char currentTile = myLevels[dlvl].getLevel()[y][x].getDisplayChar();
    if (direction == "up" && ( currentLevelChars[y-1][x] != ' ' && currentLevelChars[y-1][x] !='+'))
    {
        for (int i =0; i<myGameUnits[dlvl].size();i++)
        {
            if (y-1==myGameUnits[dlvl][i]->getY() && x==myGameUnits[dlvl][i]->getX())
                enemyClose=true;
        }
        if(!enemyClose){
        myUnit->setYX(x, y-1);
        currentLevelChars[y][x] = currentTile;
        currentLevelChars[y-1][x] = '@';
        }
    }
    
    else if (direction == "down" &&  ( currentLevelChars[y+1][x] != ' ' && currentLevelChars[y+1][x] !='+'))
    {
        for (int i =0; i<myGameUnits[dlvl].size();i++)
        {
            if (y+1==myGameUnits[dlvl][i]->getY() && x==myGameUnits[dlvl][i]->getX())
                enemyClose=true;
        }
        if(!enemyClose){
        myUnit->setYX(x, y+1);
        currentLevelChars[y][x] = currentTile;
        currentLevelChars[y+1][x] = '@';
        }
    }
    
    else if (direction == "left" &&  ( currentLevelChars[y][x-1] != ' ' && currentLevelChars[y][x-1] !='+'))
    {
        for (int i =0; i<myGameUnits[dlvl].size();i++)
        {
            if (y==myGameUnits[dlvl][i]->getY() && x-1==myGameUnits[dlvl][i]->getX())
                enemyClose=true;
        }
        if(!enemyClose){
        myUnit->setYX(x-1, y);
        currentLevelChars[y][x] = currentTile;
        currentLevelChars[y][x-1] = '@';
        }
    }
    
    
    else if (direction == "right" &&  (currentLevelChars[y][x+1] != ' ' && currentLevelChars[y][x+1] !='+'))
    {
        for (int i =0; i<myGameUnits[dlvl].size();i++)
        {
            if (y==myGameUnits[dlvl][i]->getY() && x+1==myGameUnits[dlvl][i]->getX())
                enemyClose=true;
        }
        if(!enemyClose){
        myUnit->setYX(x+1, y);
        currentLevelChars[y][x] = currentTile;
        currentLevelChars[y][x+1] = '@';
        }
    }
    

    drawLevel();
    
}




void Game::displayInventory(){
    move(23,0);
    stringstream output;
    string inventory = "";
    if (myPlayer.getWeapon()!= NULL){
    inventory = "Weapon: " + myPlayer.getWeapon()->getName();
    }
    if (myPlayer.getArmor()!= NULL)
    {
        inventory = inventory + " Armor: " + myPlayer.getArmor()->getName();
    }
    output << "Inventory: "<< inventory;
    addstr(output.str().c_str());
}



void Game::moveCreatures()
{

}












