#include <iostream>

#include "file.hpp"

int File::getNumberOfFilesInDirectory(const std::string pathToDir){
    std::string command = "ls " + pathToDir + " | wc";
    FILE* result = popen(command.c_str(), "r");
    std::string number;
    while(!feof(result)){                   // While not file end
        char c;
        // We take only one number out of three!
        if((c = fgetc(result)) != ' '){
            while(c != ' '){
                number += c;
                c = fgetc(result);
            }
            pclose(result);
            return std::stoi(number);
        }
    }
    pclose(result);
    return -1;
}


std::string File::getRandomFileNameFromDir(const std::string pathToDir){
    std::string command = "ls " + pathToDir;
    FILE* files = popen(command.c_str(), "r");   // Get the all files in a directory
    int numbersOfFiles = File::getNumberOfFilesInDirectory(pathToDir);   //Quantity the files in a directory
    int numberOfFile = std::rand() % numbersOfFiles;  // Index of the random file
    std::string file_name;

    char c;
    // Skip other files
    for(int i = 0; i < numberOfFile; i++){
        while((c = fgetc(files)) != '\n');
    }
    // Get's file
    while((c = fgetc(files)) != '\n' && (c != EOF)){
        file_name += c;
    }
    pclose(files);

    return file_name;
}
