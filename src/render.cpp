#include <iostream>

#include "render.hpp"

SDL_Renderer* Render::renderer = nullptr;

Render::Render(SDL_Window* window){
    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        std::cout << SDL_GetError();
    }
}

SDL_Renderer* Render::getRenderer()     {return  renderer;}

void Render::draw(){
    std::list<Object*> *data = Buffer::getData();
    for(std::list<Object*>::iterator object =  data->begin(); object != data->end(); object++){
        SDL_RenderCopy(renderer, (*object)->getTexture(), nullptr, (*object)->getRect());
    }
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

Render::~Render(){
    SDL_DestroyRenderer(renderer);
}
