#include <iostream>

#include "window.hpp"
#include "setting.hpp"
int main() {
    Window window("Santa Game", SCREEN_WIDTH, SCREEN_HEIGHT);
    window.update();

    return 0;
}
