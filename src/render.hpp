#ifndef RENDER_HPP
#define RENDER_HPP

#include <SDL2/SDL.h>
#include <list>

#include "buffer.hpp"
#include "object.hpp"

class Render {
private:
    static SDL_Renderer *renderer;
public:
    Render(SDL_Window *window);
    static SDL_Renderer* getRenderer();
    static void draw();
    ~Render();
};

#endif // RENDER_HPP
