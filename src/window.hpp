#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL2/SDL.h>

#include "render.hpp"
#include "game.hpp"

class Window{
    SDL_Window  *window;
    Render      *render;
    Game        *game;
    //Menu      *menu;
public:
    Window(const std::string title, const int width, const int height);
    void update() const;
    void start();
    ~Window();
};

#endif // WINDOW_HPP
