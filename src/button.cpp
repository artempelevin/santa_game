#include "button.hpp"

#include "game.hpp"

bool Button::isPressed() const      {return is_pressed;}
void Button::press()                {is_pressed = true;}
void Button::release()              {is_pressed = false;}
