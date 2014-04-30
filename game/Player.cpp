//
//  Player.cpp
//  pa1-1
//
//  Created by Aly Shehata on 2/6/14.
//  Copyright (c) 2014 Aly Shehata. All rights reserved.
//

#include "Player.h"

Player::Player()
{
    myName = "";
    myExperience = 0;
    myHealth = 100;
    myScore = 0;
    myLevel = 1;
    myDisplay = '@';
    myX = 0;
    myY = 0;
    myWeapon = NULL;
    myArmor = NULL;
}

int Player::getExperience()
{
    return myExperience;
    
}
void Player::setExperience(int experience)
{
    myExperience = experience;
}


void Player::setLevel(int level){
    myLevel = level;
}
int Player::getLevel(){
    return myLevel;
}
void Player::setHealth(int health){
    myHealth = health;
}
int Player::getHealth(){
    return myHealth;
}
int Player::getScore(){
    return myScore;
}
void Player::setScore(int score){
    myScore = score;
}


string Player::getName(){
    return myName;
}


void Player::setYX(int y, int x){
    myX = y;
    myY = x;
    
}

int Player::getX(){
    
    return myX;
}

int Player::getY(){
    
    return myY;
}

Weapon* Player::getWeapon()
{
    return myWeapon;
}
void Player::setWeapon(Weapon* weapon)
{
    myWeapon = weapon;
}
Armor* Player::getArmor()
{
    return myArmor;
}
void Player::setArmor(Armor* armor)
{
    myArmor = armor;
}


