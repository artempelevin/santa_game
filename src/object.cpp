#include <iostream>
#include <SDL2/SDL_image.h>

#include "object.hpp"
#include "render.hpp"

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

int getNumberOfFilesInDirectory(const std::string pathToDir){
    std::string command = "ls " + pathToDir + " | wc";
    FILE* result = popen(command.c_str(), "r");
    std::string number;
    while(!feof(result)){                   // While not file end
        char c;
        // We take only one number out of three!
        if((c = fgetc(result)) != ' '){
            while(c != ' '){
                number += c;
                c = fgetc(result);
            }
            pclose(result);
            return std::stoi(number);
        }
    }
    pclose(result);
    return -1;
}

Object* Object::getRandomObjectFromDir(const std::string pathToDir){
    std::string command = "ls " + pathToDir;
    FILE* textures = popen(command.c_str(), "r");   // Get the all files in a directory
    int numbersOfFiles = getNumberOfFilesInDirectory(pathToDir);   //Quantity the files in a directory
    int numberOfFile = std::rand() % numbersOfFiles;  // Index of the random file
    std::string file_name;

    char c;
    // Skip other files
    for(int i = 0; i < numberOfFile; i++){
        while((c = fgetc(textures)) != '\n');
    }
    // Get's file
    while((c = fgetc(textures)) != '\n' && (c != EOF)){
        file_name += c;
    }
    pclose(textures);

    std::string pathToFile = pathToDir + "/" + file_name;
    return getObjectFromFile(pathToFile);
}
