#include "game.hpp"
#include <iostream>

#include "buffer.hpp"
#include "render.hpp"

enum{
    X_COORDS,
    Y_COORDS
};

int Game::mouse_coords[2] = {};

void Game::loadLevel(){
    delete level;       // Free the previous level
    level = new Level();
}

void Game::render() const{
    Buffer::add(level->getCurrRoom());

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

int Game::getMouseX()       {return mouse_coords[X_COORDS];}
int Game::getMouseY()       {return mouse_coords[Y_COORDS];}

