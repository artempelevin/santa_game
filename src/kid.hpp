#ifndef CHILDREN_HPP
#define CHILDREN_HPP

#include <string>
#include "object.hpp"
#include "text.hpp"

enum{
    BOY,
    GIRL
};

class Kid {
private:
    int         gender;
    std::string name;
    std::string story;
    std::string gift;
    Object*     gitf_object;
    Object*     kid_object;
    Object*     name_object;
public:
    Kid();
    ~Kid();
    std::string getName()           const;
    std::string getStory()          const;
    std::string getGift()           const;
    Object*     getGiftObject()     const;
    Object*     getKidObject()      const;
    Object*     getNameObject()     const;
};

#endif // CHILDREN_HPP
