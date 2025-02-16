#ifndef _FILETRANSFER_H_
#define _FILETRANSFER_H_

#include <cstddef>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <cstring>
#include "md5.h"

using namespace std;


const uint8_t TYPE_META = 1; 
const uint8_t TYPE_DATA = 2; 

#define SIZE_OF_PACKET 256  
#define MAX_LENTH_OF_FILENAME 120
#define LENTH_OF_HASH 16 
#define PADDING_SIZE (SIZE_OF_PACKET - sizeof(uint8_t) - MAX_LENTH_OF_FILENAME - sizeof(uint64_t) * 2 - LENTH_OF_HASH)

#define SIZE_PAYLOAD   (SIZE_OF_PACKET - sizeof(uint8_t) - sizeof(uint64_t)) 

typedef struct MetaPacket 
{
    uint8_t   typeofpacket; 
    char      filename[MAX_LENTH_OF_FILENAME]; 
    uint64_t  fileSize; 
    uint64_t  totalBlocks; 
    uint8_t   md5[LENTH_OF_HASH]; 
    uint8_t   padding[PADDING_SIZE]; 
} MetaPacket;

#pragma pack(push, 1) 
struct BlockPacktOfFile 
{
    uint8_t   packetType; 
    uint64_t  localSequence; 
    char      payLoad[SIZE_PAYLOAD]; 
};
#pragma pack(pop)

class FileTransfer
{
private:
    int Complete = -1;                
    MetaPacket metaPacket;          
    vector<BlockPacktOfFile> blocks;      
    vector<uint8_t> fileData;        

public:
    vector<BlockPacktOfFile> BlocksRecieved(void);
    int LoadFileData(const char* filename);
    const MetaPacket& GetMetaPacket(void);
    int ReceivedFilePacket(const unsigned char* packet, size_t packetSize);
    bool FileVerification();
    int ReceivedFileData();
    int SaveFileData() const;
    
};

#endif // _FILETRANSFER_H_

