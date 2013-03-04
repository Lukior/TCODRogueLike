#include "include/libtcod.hpp"
#include "src/actor.h"
#include "src/map.h"
#include "src/engine.h"

Engine::Engine() {
    TCODConsole::initRoot(80,50,"libtcod C++ tutorial",false);
    player = new Actor(40,25,'@',TCODColor::white);
    actors.push(player);
    actors.push(new Actor(60,13,'@',TCODColor::yellow));
    actors.push(new Actor(40,20,'`',TCODColor::grey));
    map = new Map(80,45);
}

Engine::~Engine() {
    actors.clearAndDelete();
    delete map;
}

void Engine::update() {
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
    switch(key.vk) {
        case TCODK_UP :
            if ( map->isPassable(player->getPosx(),player->getPosy()-1)) {
                player->moveUp();
            }
        break;
        case TCODK_DOWN :
            if ( map->isPassable(player->getPosx(),player->getPosy()+1)) {
                player->moveDown();
            }
        break;
        case TCODK_LEFT :
            if ( map->isPassable(player->getPosx()-1,player->getPosy())) {
                player->moveLeft();
            }
        break;
        case TCODK_RIGHT :
            if ( map->isPassable(player->getPosx()+1,player->getPosy())) {
                player->moveRight();
            }
        break;
        case TCODK_CHAR :
            switch(key.c) {
                case 'c' :
                    closeDoor();
                break;
            }
        break;
        default:break;
    }
}

void Engine::closeDoor() {
    TCOD_key_t key;
    Actor *cibledDoor;
    TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL,true);
    switch(key.vk) {
        case TCODK_UP :
        for (Actor **iterator=actors.begin(); iterator != actors.end(); iterator++) {
            if (((*iterator)->getPosx()==player->getPosx()) && ((*iterator)->getPosy()==player->getPosy()-1)){
                cibledDoor = *iterator;
                cibledDoor->setClosed();
            }
        }
        break;
        case TCODK_DOWN :
        break;
        case TCODK_LEFT :
        break;
        case TCODK_RIGHT :
        break;
        default:break;
    }

}

void Engine::render() {
    TCODConsole::root->clear();
    // draw the map
    map->render();

    // draw the actors
    for (Actor **iterator=actors.begin();
        iterator != actors.end(); iterator++) {
        (*iterator)->render();
    }
}
