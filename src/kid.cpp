#include <fstream>

#include "kid.hpp"
#include "file.hpp"
#include "setting.hpp"
#include "text.hpp"

struct Story{
    std::list<std::string> text_lines;
    std::string  gift_type;
};

Story loadStoryFromFile(const std::string pathToFile){
    Story story = {};

    std::ifstream input_file(pathToFile);
    std::string line;
    char sym = 0;

    do{              // We get all the lines except the line with the gift name
        input_file.get(sym);
        if(sym != '\n' && sym != ';'){
            line += sym;
        }
        else {
            story.text_lines.push_back(line);
            line.clear();
        }

    } while(sym != ';');

    // Get the gift name
    getline(input_file, line);      // Skip the old line
    getline(input_file, line);
    story.gift_type = line;

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

    // Get the lines of the story text
    int i = 0;
    for(auto iter = allStory.text_lines.begin(); iter != allStory.text_lines.end(); iter++){
        Text text(TEXT_X, TEXT_Y + FONT_DISTANCE*i, *iter);
        story.push_back(text.getObject());
        i++;
    }

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
    Text* name_text = new Text(KID_NAME_X,
                               KID_NAME_Y,
                               name);
    name_object = name_text->getObject();

    delete name_text;

}

Kid::~Kid(){
    delete gitf_object;
    delete kid_object;
}

void                    Kid::setGiftObjectX(const int x)   {gitf_object->setX(x);}
std::string             Kid::getName()           const     {return name;}
std::list<Object*>      Kid::getStory()          const     {return story;}
std::string             Kid::getGift()           const     {return gift;}
Object*                 Kid::getGiftObject()     const     {return gitf_object;}
Object*                 Kid::getKidObject()      const     {return kid_object;}
Object*                 Kid::getNameObject()     const     {return name_object;}
