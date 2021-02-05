#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "object.hpp"

class Button: public Object{
private:
    bool is_pressed = false;
public:
    Button(const int x, const int y, const int w, const int h, SDL_Texture *const _texture): \
        Object(x, y, w, h, _texture) {}
    void press();
    void release();
    bool isPressed() const;
};

#endif // BUTTON_HPP
