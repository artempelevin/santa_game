#include <iostream>

#include "window.hpp"
#include "setting.hpp"

int main() {
    std::srand(time(nullptr));
    Window window("Santa Game", SCREEN_WIDTH, SCREEN_HEIGHT);
    window.update();

    return 0;
}
