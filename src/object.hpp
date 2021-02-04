#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

#include <SDL2/SDL.h>

class Object{
private:
    SDL_Rect    *rect;     // Coords and sizes
    SDL_Texture *texture;
public:
    Object(const int x, const int y, const int w, const int h, SDL_Texture *const _texture);
    ~Object();
    SDL_Rect*    getRect();
    SDL_Texture* getTexture();
    int getX()      const;
    int getY()      const;
    int getWidth()  const;
    int getHeight() const;
    void setX(const int x);
    void setY(const int y);
    void setCoords(const int x, const int y);
    void setWidth(const int width);
    void setHeight(const int height);
    void setSizes(const int width, const int height);
    static Object* getObjectFromFile(const std::string pathToFile);
    static Object* getRandomObjectFromDir(const std::string pathToDir);
};

#endif // OBJECT_HPP
