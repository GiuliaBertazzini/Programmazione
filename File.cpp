//
// Created by giulia on 16/09/20.
//

#include "File.h"

File::File(string filename) {
    file.open(filename);
    if(!file.is_open())
        throw runtime_error("Failed to open file");
}

File::~File() {
    file.close();
    if (file.is_open())
        throw runtime_error("Failed to close file");
}