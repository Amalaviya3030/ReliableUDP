// FileTransfer.cpp
#include "FileTransfer.h"
#include <iostream>

bool FileTransfer::SendFileMetadata(const std::string& fileName, size_t fileSize, const std::string& checksum) {
    // Empty function body
    return false;
}

bool FileTransfer::SendFileChunk(const std::vector<unsigned char>& chunk, int chunkIndex) {
    // Empty function body
    return false;
}

bool FileTransfer::ReceiveFileMetadata(std::string& fileName, size_t& fileSize, std::string& checksum) {
    // Empty function body
    return false;
}

bool FileTransfer::ReceiveFileChunk(std::vector<unsigned char>& chunk, int& chunkIndex) {
    // Empty function body
    return false;
}
