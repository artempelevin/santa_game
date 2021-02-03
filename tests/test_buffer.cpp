#include <gtest/gtest.h>
#include <list>

#include "buffer.hpp"
#include "object.hpp"

TEST(Buffer, getData){
    std::list<Object*>* data1;

    data1 = Buffer::getData();

    ASSERT_EQ(data1->size(), 0);
}

TEST(Buffer, add){
    Object* object = new Object(0, 0, 100, 100, nullptr);
    std::list<Object*>* data1;

    Buffer::add(object);
    data1 = Buffer::getData();

    ASSERT_EQ(data1->size(), 1);
    ASSERT_EQ(*data1->begin(), object);
}


TEST(Buffer, clear){
    Object* object = new Object(0, 0, 100, 100, nullptr);
    std::list<Object*>* data1;

    Buffer::add(object);
    Buffer::clear();
    data1 = Buffer::getData();

    ASSERT_EQ(data1->size(), 0);
}
