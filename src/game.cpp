#include "game.hpp"
#include <iostream>

#include "buffer.hpp"
#include "render.hpp"
#include "setting.hpp"
#include "button.hpp"
#include "text.hpp"
enum{
    X_COORD,
    Y_COORD
};

Game::Game(){
    Text::loadFont("data/fonts/Alice-Regular.ttf", 25);

    // Load buttons
    SDL_Texture* button_texture = Object::loadTexture("data/button.jpg");
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        buttons[i] = new Button(BUTTON_X + i*BUTTON_WIDTH,
                                BUTTON_Y,
                                BUTTON_WIDTH,
                                BUTTON_HEIGHT,
                                button_texture);
    }
    task_canvas = new Object(TASK_X,
                             TASK_Y,
                             TASK_WIDTH,
                             TASK_HEIGHT,
                             Object::loadTexture("data/бумага.png"));
}

Game::~Game(){
    delete level;
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++)   delete buttons[i];
    delete task_canvas;
}

void Game::loadLevel(){
    if(!level)      delete level;       // Free the previous level
    level = new Level();
}

void Game::render() const{
    Buffer::add(level->getCurrRoom());              // Background
    Buffer::add(level->getCurrKid());               // Kid
    Buffer::add(task_canvas);                       // Task_canvas

    Object** gifts = level->getGifts();
    for(int i = 0; i < MAX_ROOMS_NUMBER; i++){
        // Buttons
        Buffer::add((Object*) buttons[i]);

        // Gifts
        gifts[i]->setX(i*GIFT_WIDTH);
        Buffer::add(gifts[i]);
    }


    Render::draw();
    Buffer::clear();

    delete [] gifts;
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
        int button_id = getIdPressedButton();
        if(button_id!= -1){       // If the button was pressed
            buttons[button_id]->press();
        }
    }
}

