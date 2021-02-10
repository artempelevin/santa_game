#include "buffer.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "render.hpp"

std::list<Object*> Buffer::data;

std::list<Object*>* Buffer::getData(){
    return &data;
}

void Buffer::add(Object *object){
    data.push_back(object);
}

void Buffer::add(const int x, const int y, const int w, const int h, SDL_Texture* texture){
    data.push_back(new Object(x, y, w, h, texture));
}

void Buffer::clear(){
    data.clear();
}
