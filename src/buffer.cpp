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

void Buffer::clear(){
    data.clear();
}
