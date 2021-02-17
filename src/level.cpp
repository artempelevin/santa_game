#include <SDL2/SDL.h>

#include "level.hpp"
#include "object.hpp"

Level::Level(){
    // Generating a random level
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        rooms[i] = Object::getRandomObjectFromDir("/home/artem/C++/santa_game/data/backgrounds/");
        kids[i]  = new Kid();
    }
    placingGifts();
}

Level::~Level(){
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        delete kids[i];
    }
}

void Level::placingGifts(){
    int x_coords[MAX_ROOMS_NUMBER] = {};
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++)   x_coords[i] = GIFT_X + GIFT_WIDTH * i;
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        int index;
        do{
            index = std::rand() % MAX_ROOMS_NUMBER;
        } while(x_coords[index] == -1);
        kids[i]->setGiftObjectX(x_coords[index]);
        x_coords[index] = -1;
    }
}

Object*                Level::getCurrRoom()    const   {return rooms[room_number];}
Object*                Level::getCurrKid()     const   {return kids[room_number]->getKidObject();}
std::list<Object*>     Level::getCurrStorie()  const   {return kids[room_number]->getStory();}
Object*                Level::getCurrName()    const   {return kids[room_number]->getNameObject();}
Object**               Level::getGifts() const {
    Object** gifts = new Object*[MAX_ROOMS_NUMBER];
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        gifts[i] = kids[i]->getGiftObject();
    }
    return gifts;
}

void Level::prevRoom(){
    if(room_number)     room_number--;
}
void Level::nextRoom(){
    if(room_number < MAX_ROOMS_NUMBER-1)     room_number++;
}

