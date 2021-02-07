#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <SDL2/SDL_ttf.h>

#include "object.hpp"

class Text{
    static TTF_Font* font;
    static SDL_Color color;
    int x;
    int y;
    std::string text;
public:
    static void loadFont(std::string pathToFont, int fontSize, int color_r, int color_g, int color_b);
    Text(const int x, const int y, const std::string text);
    Object* getObject() const;
};

#endif // TEXT_HPP
