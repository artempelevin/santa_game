#include <fstream>

#include "kid.hpp"
#include "file.hpp"

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
    std::string genderStr = (gender == GIRL) ? "boys": "girls";
    std::string fileName = File::getRandomFileNameFromDir("data/stories/" + genderStr + "/");
    Story allStory = loadStoryFromFile("data/stories/" + genderStr + "/" + fileName);

    name  = File::getRandomLineFromFile("data/names/"+ genderStr + "/names.txt");
    story = allStory.story_text;
    gift  = allStory.gift_type;
    gitf_object = Object::getObjectFromFile("data/gifts/" + gift + ".jpg");
    kid_object  = Object::getRandomObjectFromDir("data/kids/" + genderStr);
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
