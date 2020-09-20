//
// Created by giulia on 15/09/20.
//

#include "LoadResources.h"

LoadResources::LoadResources() {
    numberResources = 0;
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

bool LoadResources::didLoadFile() const {
    return loaded;
}

int LoadResources::getFileSize() const {
    return filesize;
}