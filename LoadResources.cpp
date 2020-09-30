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

bool LoadResources::loadedFile() const {
    return loaded;
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

void LoadResources::load(std::vector<const char *> filenames) {
    numberResources = filenames.size();
    if (!numberResources) {
        throw std::runtime_error("Nessuna risorsa");
    }

    for (auto& it : filenames) {
        try {
            File file(it);
            filename = QString(it);
            filesize = file.getFileSize();
            loaded = true;
            notifyObservers();

        } catch (std::runtime_error &e) {
            filename = QString(it);
            loaded = false;
            notifyObservers();

        }
    }
}