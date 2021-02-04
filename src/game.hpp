#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "level.hpp"

class Game{
private:
    Level     *level;
    SDL_Event  event;
    bool       is_end = false;
    static int mouse_coords[2];
public:
    ~Game();
    void loadLevel();
    void render() const;
    bool isEnd()  const;
    bool checkEvent();
    void handleEvent();
    static int getMouseX();
    static int getMouseY();
};

#endif // GAME_HPP
