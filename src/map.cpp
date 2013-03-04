#include "include/libtcod.hpp"
#include "src/map.h"

Map::Map(int width, int height) : width(width),height(height) {
    tiles=new Tile[width*height];
    setWall(30,22);
    setWall(50,22);
}

Map::~Map() {
    delete [] tiles;
}

int Map::getMapWidth () const{
    return width;
}

int Map::getMapHeight () const{
    return height;
}

bool Map::isPassable(int x, int y) const {
    if (!((x<0) || (x>width-1)) && !((y<0) || (y>height-1))){
        return tiles[x+y*width].canWalk;
    }

    return false;

}

int Map::getChar (int x, int y) const {
    return tiles[x+y*width].tileChar;
}

void Map::setChar (int x, int y, int newChar) {
    tiles[x+y*width].tileChar = newChar;
}

TCODColor Map::getBackgroundColor (int x, int y) const {
    return tiles[x+y*width].tileBackgroundColor;
}

void Map::setBackgroundColor (int x, int y, TCODColor newColor) {
    tiles[x+y*width].tileBackgroundColor = newColor;
}

TCODColor Map::getForegroundColor (int x, int y) const {
    return tiles[x+y*width].tileForegroundColor;
}

void Map::setPassable (int x, int y, bool passable){
    tiles[x+y*width].canWalk=passable;
}

void Map::setForegroundColor (int x, int y, TCODColor newColor) {
    tiles[x+y*width].tileForegroundColor = newColor;
}

void Map::setWall(int x, int y) {
    tiles[x+y*width].canWalk=false;
    setChar(x, y, '#');
}

void Map::render() const {
    for (int x=0; x < width; x++) {
        for (int y=0; y < height; y++) {
            TCODConsole::root->setCharBackground(x, y, getBackgroundColor(x,y));
            TCODConsole::root->setCharForeground(x, y, getForegroundColor(x,y));
            TCODConsole::root->setChar(x, y, getChar(x,y));
        }
    }
}
