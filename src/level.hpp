#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "setting.hpp"
#include "object.hpp"
#include "button.hpp"
class Level{
private:
    //Children childrens[MAX_ROOMS_NUMBER];
    Object*     rooms[MAX_ROOMS_NUMBER];
    Object*     gifts[MAX_ROOMS_NUMBER];
    std::string stories[MAX_ROOMS_NUMBER];
    /* Other data */
    int room_number = 0;
public:
    Level();
    Object*     getCurrRoom()       const;
    Object*     getCurrGift()       const;
    std::string getCurrstorie()     const;
};

#endif // LEVEL_HPP
