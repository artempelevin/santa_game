#include <iostream>

#include "window.hpp"

Window::Window(const std::string title, const int width, const int height){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << SDL_GetError();
    }
    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_OPENGL
                              );
    if(window == nullptr){
        std::cout << SDL_GetError();
    }

    render = new Render(window);
    game   = new Game();
    game->loadLevel();
}

Window::~Window(){
    SDL_DestroyWindow(window);
}

void Window::update() const{
    while(!game->isEnd()){
        if(game->checkEvent()){
            game->handleEvent();
            game->render();
            game->releaseButtons();
        }
        SDL_Delay(10);
    }
}
