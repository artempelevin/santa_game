#include <SDL2/SDL.h>

#include "level.hpp"
#include "object.hpp"

Level::Level(){
    // Generating a random level
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        rooms[i] = Object::getRandomObjectFromDir("/home/artem/C++/santa_game/data/backgrounds/");
        kids[i]  = new Kid();
    }
}

Level::~Level(){
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        delete kids[i];
    }
}

Object*     Level::getCurrRoom()    const   {return rooms[room_number];}
Object*     Level::getCurrKid()     const   {return kids[room_number]->getKidObject();}
std::string Level::getCurrStorie()  const   {return kids[room_number]->getStory();}
Object**    Level::getGifts() const {
    Object** gifts = new Object*[MAX_ROOMS_NUMBER];
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        gifts[i] = kids[i]->getGiftObject();
    }
    return gifts;
}
