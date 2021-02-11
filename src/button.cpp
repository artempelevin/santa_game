#include "button.hpp"

#include "game.hpp"

bool Button::isPressed() const      {return is_pressed;}

void Button::press(){
    if(is_pressed)  is_pressed = false;
    else            is_pressed = true;
}
