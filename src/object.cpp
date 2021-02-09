#include <iostream>
#include <SDL2/SDL_image.h>

#include "object.hpp"
#include "render.hpp"
#include "file.hpp"

Object::Object(const int x, const int y, const int w, const int h, SDL_Texture *const _texture){
    rect = new SDL_Rect{x, y, w, h};
    texture = _texture;
}

Object::~Object(){
    SDL_DestroyTexture(texture);
    delete rect;
}

SDL_Rect*    Object::getRect()          {return rect;}
SDL_Texture* Object::getTexture()       {return texture;}
int Object::getX()      const           {return rect->x;}
int Object::getY()      const           {return rect->y;}
int Object::getWidth()  const           {return rect->w;}
int Object::getHeight() const           {return rect->h;}

void Object::setX(const int x){
    rect->x = x;
}
void Object::setY(const int y){
    rect->y = y;
}
void Object::setCoords(const int x, const int y){
    rect->x = x;
    rect->y = y;
}
void Object::setWidth(const int width){
    rect->w = width;
}
void Object::setHeight(const int height){
    rect->h = height;
}
void Object::setSizes(const int width, const int height){
    rect->w = width;
    rect->h = height;
}


SDL_Texture* Object::loadTexture(const std::string pathToFile){
    SDL_Surface* surface = IMG_Load(pathToFile.c_str());
    if(surface == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Render::getRenderer(), surface);
    if(texture == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    return texture;
}

Object* Object::getObjectFromFile(const std::string pathToFile){
    SDL_Surface* surface = IMG_Load(pathToFile.c_str());
    if(surface == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Render::getRenderer(), surface);
    if(texture == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    Object* object = new Object(0, 0, surface->w, surface->h, texture);
    SDL_FreeSurface(surface);
    return object;
}


Object* Object::getRandomObjectFromDir(const std::string pathToDir){
    std::string file_name  = File::getRandomFileNameFromDir(pathToDir);
    std::string pathToFile = pathToDir + "/" + file_name;

    return getObjectFromFile(pathToFile);
}
