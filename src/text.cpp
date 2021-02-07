#include "text.hpp"
#include "render.hpp"

TTF_Font* Text::font = nullptr;
SDL_Color Text::color = {0, 0, 0, 255};

void Text::loadFont(std::string pathToFont, int fontSize, int color_r, int color_g, int color_b){
    if(TTF_Init() == -1){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    font = TTF_OpenFont(pathToFont.c_str(), fontSize);
    if(font == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    color.r = color_r;
    color.g = color_g;
    color.b = color_b;
}

Text::Text(const int x, const int y, const std::string text): x(x), y(y), text(text) {}

Object* Text::getObject() const {
    SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
    if(surf == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    int w = surf->w;
    int h = surf->h;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(Render::getRenderer(), surf);
    if(texture == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    SDL_FreeSurface(surf);

    Object *object = new Object(x, y, w, h, texture);

    return  object;
}
