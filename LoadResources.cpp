//
// Created by giulia on 15/09/20.
//

#include <iostream>
#include "LoadResources.h"

LoadResources::LoadResources() {
    numberResources = 0;
    loaded = false;
}

void LoadResources::registerObserver(Observer *obs) {
    observers.push_back(obs); //inserisce in fondo alla lista
}

void LoadResources::removeObserver(Observer *obs) {
    observers.remove(obs);
}

void LoadResources::notifyObservers() const {
    for(const auto &itr : observers){
        itr -> update();              //scorro tutti gli osservatori registrati e chiamo update
    }
}

bool LoadResources::loadedFile() const {
    return loaded;
}

void LoadResources::setLoad(bool l) {
    loaded=l;
}

int LoadResources::getFileSize() const {
    return filesize;
}

int LoadResources::getNumberResources() const {
    return numberResources;
}

const QString & LoadResources::getFileName() {
    return filename;
}


void LoadResources::load(std::vector<const char *> &filenames) {
    try {
        numberResources = filenames.size();
        if (numberResources==0) {
            throw std::runtime_error("Nessuna risorsa");
        }
    } catch (std::runtime_error& e) {
        std::cerr<<e.what()<<std::endl;
    }
    for (auto &it : filenames) {
        handleFile(it);
    }
}

void LoadResources::handleFile(const char *it) {
    try {
        File file(it);
        filename = QString(it);
        filesize = file.getFileSize();
        setLoad(true);
        notifyObservers();

    } catch (std::runtime_error &e) {
        filename = QString(it);
        setLoad(false);
        notifyObservers();

    } catch (...) {
        std:cerr<< "Unknown exception" << std::endl;
    }
}
