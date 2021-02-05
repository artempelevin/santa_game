#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "level.hpp"

class Game{
private:
    Level     *level;
    Button*    buttons[MAX_ROOMS_NUMBER];
    SDL_Event  event;
    bool       is_end = false;
    int mouse_coords[2];
public:
    Game();
    ~Game();
    void loadLevel();
    void render() const;
    bool isEnd()  const;
    bool checkEvent();
    void handleEvent();
};

#endif // GAME_HPP
