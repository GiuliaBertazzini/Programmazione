//
// Created by giulia on 16/09/20.
//

#include "File.h"

File::File(const char* filename): file(fopen(filename, "r")), fileSize(0) { //apre il file chiamato filename e l'access mode al file è read

    if(!file)
        throw runtime_error("Failed to open file");
    else {
        fseek(file, 0, SEEK_END); //dist=0 di quanti byte deve essere spostato il file pointer, partenza da quale posizione deve essere spostanto (END fine del file)
        fileSize= static_cast<int>(ftell(file)); //dimensione in byte
    }

}

File::~File() {
    if(fclose(file))   //flocse ritorna 0 se ha avuto successo
        throw runtime_error("Failed to close file");
}

int File::getFileSize() {
    return fileSize;
}