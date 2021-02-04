#include "game.hpp"
#include "buffer.hpp"
#include "render.hpp"

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
}
