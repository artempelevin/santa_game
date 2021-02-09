#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class File{
public:
    static int getNumberOfFilesInDirectory(const std::string pathToDir);
    static std::string getRandomFileNameFromDir(const std::string pathToDir);
    static std::string getRandomLineFromFile(const std::string pathToFile);
};
#endif // FILE_HPP
