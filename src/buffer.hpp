#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <list>
#include <string>

#include "object.hpp"

class Buffer {
private:
    Buffer() {}                           // Objects don't exist
    static std::list<Object*> data;
public:
    static std::list<Object*>* getData();
    static void add(Object *object);
    static void add(const int x, const int y, const int w, const int h, SDL_Texture* texture);
    static void clear();
};

#endif // BUFFER_HPP
