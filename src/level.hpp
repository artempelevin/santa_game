#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "setting.hpp"
#include "object.hpp"
#include "button.hpp"
#include "kid.hpp"

class Level{
private:
    //Children childrens[MAX_ROOMS_NUMBER];
    Object*     rooms[MAX_ROOMS_NUMBER];
    Kid*        kids[MAX_ROOMS_NUMBER];
    /* Other data */
    int room_number = 0;            // By default - the first room
public:
    Level();
    ~Level();
    Object**                getGifts()          const;
    Object*                 getCurrRoom()       const;
    Object*                 getCurrKid()        const;
    Object*                 getCurrName()       const;
    std::list<Object*>      getCurrStorie()     const;
    void prevRoom();
    void nextRoom();
};

#endif // LEVEL_HPP
