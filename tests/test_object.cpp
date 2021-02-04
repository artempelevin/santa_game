#include <gtest/gtest.h>

#include "object.hpp"

TEST(Object, getRect){
    Object* object = new Object(1, 2, 3, 4, nullptr);
    SDL_Rect *rect = nullptr;

    rect = object->getRect();

    ASSERT_EQ(rect->x, 1);
    ASSERT_EQ(rect->y, 2);
    ASSERT_EQ(rect->w, 3);
    ASSERT_EQ(rect->h, 4);
}

TEST(Object, getTexture){
    Object* object = new Object(1, 2, 3, 4, nullptr);
    SDL_Texture *texture;

    texture = object->getTexture();

    ASSERT_EQ(texture, nullptr);
}
