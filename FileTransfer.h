// FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>

class FileHandler {
public:
    // Loads a file from disk into a buffer from the aryan 
    static bool LoadFile(const std::string& filePath, std::vector<unsigned char>& buffer);

    // Saves a buffer to disk as a file
    static bool SaveFile(const std::string& filePath, const std::vector<unsigned char>& buffer);

    // Verifies the integrity of a file using a checksum
    static std::string CalculateChecksum(const std::vector<unsigned char>& buffer);
    static bool VerifyChecksum(const std::vector<unsigned char>& buffer, const std::string& expectedChecksum);
};

#endif // FILEHANDLER_H