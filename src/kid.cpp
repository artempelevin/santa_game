#include <fstream>

#include "kid.hpp"
#include "file.hpp"
#include "setting.hpp"

struct Story{
    std::string story_text;
    std::string gift_type;
};

Story loadStoryFromFile(const std::string pathToFile){
    Story story = {};

    std::ifstream input_file(pathToFile);
    if(input_file.is_open()){
        getline(input_file, story.story_text);      // The first line is always a story
        getline(input_file, story.gift_type);       // The second line is always a gift_type
    }
    input_file.close();
    return story;
}

Kid::Kid(){
    gender = std::rand() % 2;       // 0 - BOY; 1 - GIRL
    std::string genderStr = (gender == GIRL) ? "boys": "girls"; // Get dir name
    std::string fileName = File::getRandomFileNameFromDir("data/stories/" + genderStr);
    Story allStory = loadStoryFromFile("data/stories/" + genderStr + "/" + fileName);


    std::string pathToName = "data/names/"+ genderStr + "/names" + TEXT_FORMAT;
    std::string pathToGift = "data/gifts/" + allStory.gift_type + IMAGE_FORMAT;
    std::string pathToKid  = "data/kids/" + genderStr + "/" +
                             File::getRandomFileNameFromDir("data/kids/" + genderStr);

    name  = File::getRandomLineFromFile(pathToName);
    story = allStory.story_text;
    gift  = allStory.gift_type;
    gitf_object = new Object(GIFT_X,
                             GIFT_Y,
                             GIFT_WIDTH,
                             GIFT_HEIGHT,
                             Object::loadTexture(pathToGift));
    kid_object  = new Object(KID_X,
                             KID_Y,
                             KID_WIDTH,
                             KID_HEIGHT,
                             Object::loadTexture(pathToKid));

}

Kid::~Kid(){
    delete gitf_object;
    delete kid_object;
}

std::string Kid::getName()           const     {return name;}
std::string Kid::getStory()          const     {return story;}
std::string Kid::getGift()           const     {return gift;}
Object*     Kid::getGiftObject()     const     {return gitf_object;}
Object*     Kid::getKidObject()      const     {return kid_object;}
