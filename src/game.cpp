#include "game.hpp"
#include <iostream>

#include "buffer.hpp"
#include "render.hpp"
#include "setting.hpp"
#include "button.hpp"

enum{
    X_COORD,
    Y_COORD
};

Game::Game(){
    // Load buttons
    SDL_Texture* button_texture = Object::loadTexture("data/button.jpg");
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        buttons[i] = new Button(i*90, 550, 90, 50, button_texture);
    }
    task_canvas = new Object(600, 20, 300, 450, Object::loadTexture("data/бумага.png"));
}

void Game::loadLevel(){
    if(!level)      delete level;       // Free the previous level
    level = new Level();
}

void Game::render() const{
    Buffer::add(level->getCurrRoom());              // Background
    Buffer::add(task_canvas);                       // Task_canvas
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

int Game::getIdPressedButton() const{
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        int x  = buttons[i]->getX();         int y  = buttons[i]->getY();
        int w  = buttons[i]->getWidth();     int h  = buttons[i]->getHeight();
        int _x = mouse_coords[X_COORD];      int _y = mouse_coords[Y_COORD];
        if((_x >= x && _x <= x + w) && (_y >= y && _y <= y + h))    return i;   // Return button ID
    }
    return -1;
}

void Game::releaseButtons(){
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        buttons[i]->release();
    }
}

void  Game::handleEvent(){
    if(event.type == SDL_QUIT)      is_end = true;
    if(event.type == SDL_MOUSEBUTTONDOWN){
        mouse_coords[X_COORD] = event.button.x;
        mouse_coords[Y_COORD] = event.button.y;
        if(getIdPressedButton() != -1){       // If the button was pressed
            buttons[getIdPressedButton()]->press();
        }
    }
}

