#include "level.hpp"
#include "object.hpp"

Level::Level(){
    // Generating a random level
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        rooms[i] = Object::getRandomObjectFromDir("/home/artem/C++/santa_game/data/backgrounds/");
    }
}

Object* Level::getCurrRoom()      const    {return rooms[room_number];}
Object* Level::getCurrGift()      const    {return gifts[room_number];}
std::string Level::getCurrstorie()const    {return stories[room_number];}

