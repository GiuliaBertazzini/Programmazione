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
    File(string filename);
    ~File();

private:
    fstream file;
};

#endif //PROGRAMMAZIONE_FILE_H
