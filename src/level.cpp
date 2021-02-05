#include <SDL2/SDL.h>

#include "level.hpp"
#include "object.hpp"

Level::Level(){
    // Generating a random level
    SDL_Texture* button_texture = Object::loadTexture("data/button.jpg");
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        rooms[i] = Object::getRandomObjectFromDir("/home/artem/C++/santa_game/data/backgrounds/");
        buttons[i] = new Button(i*90, 550, 90, 50, button_texture);
    }
}

Object*     Level::getCurrRoom()    const   {return rooms[room_number];}
Object*     Level::getCurrGift()    const   {return gifts[room_number];}
std::string Level::getCurrstorie()  const   {return stories[room_number];}
Button**    Level::getButtons()             {return buttons;}
