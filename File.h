//
// Created by giulia on 16/09/20.
//

#ifndef PROGRAMMAZIONE_FILE_H
#define PROGRAMMAZIONE_FILE_H

#include <fstream>
#include <string>
using namespace std;

class File{
public:
    explicit File(const char* filename);
    ~File();
    int getFileSize();

private:
    FILE *file;
    int fileSize;

};

#endif //PROGRAMMAZIONE_FILE_H
