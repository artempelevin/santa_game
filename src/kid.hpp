#ifndef CHILDREN_HPP
#define CHILDREN_HPP

#include <string>
#include <list>
#include "object.hpp"
#include "text.hpp"

enum{
    BOY,
    GIRL
};

class Kid {
private:
    int                     gender;
    std::string             name;
    std::string             gift;
    std::list<Object*>      story;         // The text is divided into lines. 1 string = 1 Object*
    Object*                 gitf_object;
    Object*                 kid_object;
    Object*                 name_object;
public:
    Kid();
    ~Kid();
    std::string             getName()           const;
    std::list<Object*>      getStory()          const;
    std::string             getGift()           const;
    Object*                 getGiftObject()     const;
    Object*                 getKidObject()      const;
    Object*                 getNameObject()     const;
};

#endif // CHILDREN_HPP
