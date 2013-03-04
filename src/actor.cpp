#include "include/libtcod.hpp"
#include "src/actor.h"
#include "src/map.h"

Actor::Actor(int x, int y, int actorChar, const TCODColor &actorColor) :
    x(x),y(y),actorChar(actorChar),actorColor(actorColor) {
}

void Actor::render() const {
    TCODConsole::root->setChar(x,y,actorChar);
    TCODConsole::root->setCharForeground(x,y,actorColor);
}

int Actor::getPosx() const{
    return x;
}

int Actor::getPosy() const{
    return y;
}

int Actor::getChar() const{
    return actorChar;
}

TCODColor Actor::getColor() const{
    return actorColor;
}

void Actor::setPosx(int newX){
    x = newX;
}

void Actor::setPosy(int newY){
    y = newY;
}

void Actor::setChar(int newChar){
    actorChar = newChar;
}

void Actor::setColor(TCODColor newColor){
    actorColor = newColor;
}

void Actor::moveUp(){
    y--;
}

void Actor::moveDown(){
    y++;
}

void Actor::moveLeft(){
    x--;
}

void Actor::moveRight(){
    x++;
}

void Actor::setClosed(){
    isClosed = true;
    actorChar = '+';
    Map::getInstance().setPassable(x,y,false);
}
