#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "level.hpp"

class Game{
private:
    Level*      level;
    Button*     buttons[MAX_ROOMS_NUMBER];
    Object*     task_canvas;
    SDL_Event   event;
    bool        is_end = false;
    int         mouse_coords[2];
private:
    int  getIdPressedButton() const;
public:
    Game();
    ~Game();
    void loadLevel();
    void render() const;
    bool isEnd()  const;
    bool checkEvent();
    void handleEvent();
    void releaseButtons();
};

#endif // GAME_HPP
