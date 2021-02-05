#include "game.hpp"
#include <iostream>

#include "buffer.hpp"
#include "render.hpp"
#include "setting.hpp"
#include "button.hpp"

enum{
    X_COORDS,
    Y_COORDS
};

Game::Game(){

    SDL_Texture* button_texture = Object::loadTexture("data/button.jpg");
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        buttons[i] = new Button(i*90, 550, 90, 50, button_texture);
    }

}

void Game::loadLevel(){
    if(!level)      delete level;       // Free the previous level
    level = new Level();
}

void Game::render() const{
    Buffer::add(level->getCurrRoom());              // Background

    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){      // Buttons
        Buffer::add((Object*) buttons[i]);
    }

    Render::draw();
    Buffer::clear();
}

bool Game::isEnd() const        {return is_end;}

bool Game::checkEvent(){
    return SDL_PollEvent(&event);
}

void  Game::handleEvent(){
    if(event.type == SDL_QUIT)      is_end = true;
    if(event.type == SDL_MOUSEBUTTONDOWN){
        mouse_coords[X_COORDS] = event.button.x;
        mouse_coords[Y_COORDS] = event.button.y;
    }
}

